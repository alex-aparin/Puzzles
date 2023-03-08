/*
 * Snake.c
 *
 * Created: 11/20/2020 8:27:30 PM
 * Author : Alex
 */ 

#include <avr/io.h>
#include <string.h>
#include <time.h>
#include <avr/interrupt.h>


#define MAP_HC595_PORT   PORTB
#define MAP_HC595_DDR    DDRB
#define MAP_ROW_HC595_RES_POS   PB5 //	Serial register pin location
#define MAP_ROW_HC595_RCLK_POS  PB4 //	Storage register clock pin location
#define MAP_ROW_HC595_SRLCK_POS PB3 //	Shift register clock pin location
#define MAP_COL_HC595_RES_POS   PB2 //	Serial register pin location
#define MAP_COL_HC595_RCLK_POS  PB1 //	Storage register clock pin location
#define MAP_COL_HC595_SRLCK_POS PB0 //	Shift register clock pin location

typedef unsigned char byte;
enum GameState
{
	Start,
	Run,
	FailEnd,
	SuccessEnd
};

enum SnakeDir
{
	/*	TODO: (alex) set proper values*/
	Up,
	Down,
	Right,
	Left
};

struct Snake
{
	byte head;
	byte tail;
	byte food;
	enum SnakeDir dir;
};

struct Game
{
	struct Snake snake;
	byte map[8][8];	
	byte empty_cells;
	enum GameState state;
};

static const byte w = 8;
static const byte h = 8;
static const byte size = 8 * 8;
static struct Game global_game;
static byte led_matrix_row = 0x0;

byte get_next_head(struct Game* game)
{
	byte i = game->snake.head / h;
	byte j = game->snake.head % w;
	switch (game->snake.dir)
	{
		case Up:
			i = (i + h - 1) % h;
		break;
		case Down:
			i = (i + h + 1) % h;
		break;
		case Right:
			j = (j + w + 1) % w;
		break;
		case Left:
			j = (j + w - 1) % w;
		break;
	}
	return i * h + j;
}
byte* get_cell(struct Game* game, const byte index)
{
	return &game->map[index / h][index % w];
}

void next_food(struct Game* game)
{
	byte random_empty_cell_index = 10;//rand() % game->empty_cells;
	for (byte i = 0; i < h; ++i)
	{
		for (byte j = 0; j < w; ++j)
		{
			if (game->map[i][j] == 0)
			{
				if (random_empty_cell_index-- == 0)
				{
					game->snake.food = i * h + j;
					*get_cell(game, game->snake.food) = size;
					break;
				}
			}
		}
	}
}


void initialize_game(struct Game* game)
{
	srand(1);

	//	Game initialization
	memset(game, 0, sizeof(struct Game));
	game->state = Run;	//	Minor hack to skip keyboard reading
	game->empty_cells = 8 * 8 - 1;
	//	Snake initialization
	game->snake.head = 0; //rand() % size;
	game->snake.tail = game->snake.head;
	game->snake.food = game->snake.food;
	game->snake.dir  = Up;
	//	Map initialization
	*get_cell(game, game->snake.head) = size;
	next_food(game);

	//	Resources initialization
	//	Set pins to manage led matrix
	MAP_HC595_DDR = 1 << MAP_ROW_HC595_RES_POS | 1 << MAP_ROW_HC595_RCLK_POS | 1 << MAP_ROW_HC595_SRLCK_POS | 
				    1 << MAP_COL_HC595_RES_POS | 1 << MAP_COL_HC595_RCLK_POS | 1 << MAP_COL_HC595_SRLCK_POS;
	MAP_HC595_PORT = 0;

	TCCR0A = 0x0;	//	enable normal mode of timer
	TCCR0B = 1 << 2 | 1;	//	enable prescaling (256)
	TIMSK0 = 1;	//	enable timer ovf interrupt

	TCCR2A = 0x0;	//	enable normal mode of timer
	TCCR2B = 1 << 2 | 1 << 1 | 1;	//	enable prescaling (1024)
	TIMSK2 = 1;	//	enable timer ovf interrupt
	sei();
}

void move_snake(struct Game* game)
{
	//	Head propagation
	{
		const byte new_head = get_next_head(game);
		if (*get_cell(game, new_head) != 0)	//	Collision with tail (game over)
		{
			game->state = FailEnd;
			return;
		}
		*get_cell(game, new_head) = size;
		*get_cell(game, game->snake.head) = new_head;
		game->snake.head = new_head;
	}
	//	Unlinking tail
	if (game->snake.head != game->snake.food)
	{
		const byte old_tail = game->snake.tail;	
		game->snake.tail = *get_cell(game, game->snake.tail);
		*get_cell(game, old_tail) = 0;
	}
	else
	{
		--game->empty_cells;
		if (game->empty_cells == 0)
		{
			game->state = SuccessEnd;
			return;
		}
		next_food(game);
	}
}

/*
		Renders row of LED matrix through specified by index
		Params: game (stores map data), row index
*/
void render_row(struct Game* game, byte row_index)
{
	MAP_HC595_PORT = 0;
	{
		//	Set row diodes pins
		byte shifted_byte = ~(1 << (7 - row_index));
		for (uint8_t i = 0; i < 8; ++i)
		{
			//	Set data for column
			MAP_HC595_PORT = (shifted_byte & 0x1) << MAP_ROW_HC595_RES_POS;
			//	Pulse for shift register of row
			MAP_HC595_PORT |= 1 << MAP_ROW_HC595_SRLCK_POS;
			MAP_HC595_PORT &= ~(1 << MAP_ROW_HC595_SRLCK_POS);
			shifted_byte = shifted_byte >> 1;
		}
		//	Pulse for storage register of ROW
		MAP_HC595_PORT |= 1 << MAP_ROW_HC595_RCLK_POS;
		MAP_HC595_PORT &= ~(1 << MAP_ROW_HC595_RCLK_POS);
	}
	{
		for (uint8_t i = 0; i < 8; ++i)
		{
			//	Set data for column
			MAP_HC595_PORT = (game->map[row_index][7 - i] != 0 ? 1 : 0) << MAP_COL_HC595_RES_POS;
			//	Pulse for shift register of column
			MAP_HC595_PORT |= 1 << MAP_COL_HC595_SRLCK_POS;
			MAP_HC595_PORT &= ~(1 << MAP_COL_HC595_SRLCK_POS);
		}
		//	Pulse for storage register of column
		MAP_HC595_PORT |= 1 << MAP_COL_HC595_RCLK_POS;
		MAP_HC595_PORT &= ~(1 << MAP_COL_HC595_RCLK_POS);
	}
}


ISR (TIMER0_OVF_vect)
{
	//	interrupt at ~240Hz 
	led_matrix_row = (led_matrix_row + 1) % h;
	//	Handling
	//if (global_game.state == Run)
	//{
		//move_snake(&global_game);
	//}
	//	Displays
	switch (global_game.state)
	{
		case Run:
		case Start:
			render_row(&global_game, led_matrix_row);
		break;
		case SuccessEnd:
		case FailEnd:
		break;
	}
}


//static byte sec_counter = 0;
//static byte temp_i = 0;
//ISR (TIMER2_OVF_vect)
//{
	//++sec_counter;
	//if (sec_counter == 1)
	//{
		//sec_counter = 0;
		//temp_i = (temp_i + 1) % h;
		//global_game.map[temp_i][temp_i] = size;
	//}
//}

int main(void)
{
	initialize_game(&global_game);
    for(;;)
    {
		if (global_game.state == Run)
		{
			//	Updation direction
		}
    }
}

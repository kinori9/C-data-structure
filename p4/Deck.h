#ifndef ___Deck
#define ___Deck

enum {DeckA, DeckB};

typedef struct {
	int front;
	int rear;
	int max;
	int num;
	int* que;
} Deck;

// 초기화
int		Initialize(Deck* d, int max);

// 인큐
int		Enque(Deck* d, int sw, int x);

// 디큐
int		Deque(Deck* d, int sw, int* x);

// 현재 num 사이즈
int		Size(const Deck* d);

// 용량
int		Capacity(const Deck* d);

// 피크
int		Peek(Deck* d, int sw, int* x);

// 데이터 프린트
void	Print(Deck* d);

// 터미널 종료
void	Terminate(Deck* d);

#endif

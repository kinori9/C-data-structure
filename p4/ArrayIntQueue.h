#ifndef ___ArrayIntQueue
#define ___ArrayIntQueue

typedef struct {
	int max;	// 큐의 용량
	int num;	// 현제 데이터 수
	int front;	// 데이터 앞의 포인터
	int rear;	// 데이터 후방 포인터	
	int* que;	// 큐의 첫요소에 대한 포인터
} ArrayIntQueue;

//배열 초기화
int		initialize(ArrayIntQueue* q, int max);

// 큐에 데이터 넣기
int		Enqueue(ArrayIntQueue* q, int x);

// 큐에서 데이터 꺼내기
int		Dequeue(ArrayIntQueue* q);

// 피크데이터 몰래보기
int		Peek(ArrayIntQueue* q, int* x);

// 큐내용 보기
void	Print(const ArrayIntQueue* q);

// 큐 종료하기
void	Terminate(ArrayIntQueue* q);

#endif

#include <unistd.h>

int main(int argc, char *argv[])
{
	
	// 수행하는 프로세스를 execl에 적힌 명령으로 바꾸는것
	execl("/bin/ps","ps","-ef",NULL);
	return 0;

}

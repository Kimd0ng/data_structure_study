#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue_simulation.h"

void main()
{
	int duration;

	srand(time(NULL));

	while (current_time < MAX_SIMUL_TIME) {
		printf("\n===== time %d ===== \n", current_time);

		// �� job�� ������ ť�� ����
		if (is_job_arrived()) {
			++new_job_id;
			duration = get_random_duration();
			insert_job_into_queue(new_job_id, current_time, duration);
		}

		// �����Ͱ� ��� ������ ���� job�� ����
		if (is_printer_idle()) {
			if (!is_queue_empty()) process_next_job();
		}
		// ���� ����Ʈ ���̸�, ���� job�� remaining time�� �ϳ� ���� 
		else {
			printf(" ���� Jop <%d>�� ����Ʈ�ϰ� �ֽ��ϴ� ... \n", current_job_id);
			--remaining_time;
		}

		// ���� ť�� ���¸� ������ 
		queue_show();
		++current_time;
	}

	// MAX_TIME�� ���� �� ��� �ڷ� ��� 
	printf("\n�Ϸ�� ����Ʈ job = %d �� \n", num_printed_jobs);
	printf("��� ���� �ð�    = %f �����ð� \n\n", (double)total_wait_time / num_printed_jobs);
}

// ID�� id, ��û�ð��� arrival_time, ����Ʈ �ð��� duration�� Job�� ť�� ����
void insert_job_into_queue(int id, int arrival_time, int duration)
{
	Job p;
	// id, arrival_time, duration ���� �� job p�� ť�� ����
	p.id = id;
	p.arrival_time = arrival_time;
	p.duration = duration;
	// addq() ���
	addq(p);
	printf(" �� jop <%d>�� ��� �Խ��ϴ�. ����Ʈ �ð��� = %d �Դϴ�. \n", id, duration);
}

// ���� job�� ť���� ���� ����(���� job id, remaining time �� ����)
void process_next_job()
{
	Job p;
	// deleteq() ���
	p = deleteq();
	// ���� job�� ť���� ������
	current_job_id = p.id;
	remaining_time = p.duration - 1;
	total_wait_time += current_time - p.arrival_time;

	++num_printed_jobs;

	printf(" ����Ʈ�� �����մϴ� - jop <%d>... \n", current_job_id);
}

// �����ϰ� true Ȥ�� false. True�� Ȯ���� ARRIVAL_PROB
boolean is_job_arrived()
{
	if (random() < JOB_ARRIVAL_PROB)
		return true;
	else
		return false;
}

// �����Ͱ� ��� ������(���� job�� remaining time <= 0) true
boolean is_printer_idle()
{
	if (remaining_time <= 0)
		return true;
	else
		return false;
}

// 0.0 - 1.0 ������ ���� ���� ��ȯ 
double random()
{
	return rand() / (double)RAND_MAX;
}

// 1 - MAX_PRINTING_TIME+1 ������ ���� ���� ��ȯ
int get_random_duration()
{
	return (int)(MAX_PRINTING_TIME * random()) + 1;
}

void addq(Element e)
{
	queue_pointer temp = (queue_pointer)malloc(sizeof(queue));
	temp->item = e;
	temp->link = NULL;

	if (front == NULL)
		front = rear = temp;
	else
	{
		rear->link = temp;
		rear = temp;
	}
}

Element deleteq()
{
	queue_pointer temp;
	Element item;

	item = front->item;
	temp = front;

	front = front->link;
	free(temp);

	return item;
}

// ���� ť�� �ִ� job�� id ���� ����Ʈ
void queue_show()
{
	queue_pointer temp;

	temp = front;

	printf("\n");
	while (temp != NULL)
	{
		printf("%c  ", temp->item);
		temp = temp->link;
	}
}

boolean is_queue_empty()
{
	if (front == NULL)
		return true;
	else
		return false;
}


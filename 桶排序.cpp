#include <queue>
#include <vector>
#include <iostream>

using namespace std;
template<typename T>
void mybucketSort(queue<T>& Inqueue, queue<T>& Outqueue)
{
	int to_out = 1;
	int maxsize = 10;
	vector<queue<T>> buckets;
	while (!Inqueue.empty())
	{
		if (Inqueue.front() == to_out) {//�����������ж�ͷԪ�ص���to_out��ֱ�ӽ�Outqueue
			Outqueue.push(Inqueue.front());
			Inqueue.pop();
			to_out++;
		}
		if (Inqueue.front() != to_out) {//�����������ж�ͷԪ�ز�����to_out����Ͱ
			 int selected_bucket = -1;
			 for (int i = 0; i < buckets.size(); i++) {
				 if (Inqueue.front() > buckets[i].back()) {//�����������ж�ͷԪ�ش���Ͱ�Ķ�βԪ��
					 if (selected_bucket == -1 || buckets[i].back() >= buckets[selected_bucket].back()) {
						 selected_bucket = i;//ѡ�����������Ͱ���棬��βԪ������Ͱ
						// break;
					 }
				 }
			 }
			 if (selected_bucket != -1) {
				 buckets[selected_bucket].push(Inqueue.front());//��Inqueue.front��ѡ��õĶ�
			 }
			 else {
				
				 queue<T> new_bucket;
				 new_bucket.push(Inqueue.front());
				 buckets.push_back(new_bucket);//���û�з���������Ͱ���½�һ��buket��Ԫ�����
				
			 }

		 }
		 Inqueue.pop();
		}
	for (int i = 0; i < buckets.size(); i++) {
		while (!buckets[i].empty()) {
			if (buckets[i].front() == to_out) {//Ͱ�Ķ�ͷԪ����û�к�to_out��ȵ�
				Outqueue.push(buckets[i].front());
				buckets[i].pop();
				to_out++;
			}
			else {//Ͱ�Ķ�ͷԪ��û�к�to_out��ȵ�
				vector<T> sorted_elements;//װ������Ͱ�е�Ԫ��

				for (int i = 0; i < buckets.size(); i++) {//��������Ͱ
					while (!buckets[i].empty()) {
						sorted_elements.push_back(buckets[i].front());
						buckets[i].pop();
					}
				}

				// �Ը��������е�Ԫ������
				sort(sorted_elements.begin(), sorted_elements.end());

				// ��������Ԫ�����μ��뵽Outqueue��
				for (int i = 0; i < sorted_elements.size(); i++) {
					Outqueue.push(sorted_elements[i]);
				}
				
			}

		}
	}

	}



 int main() {
	 queue<int> inqueue;
	 queue<int> outqueue;
	 srand((unsigned int)time(NULL));

		 vector<int> elements = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		
		 random_shuffle(elements.begin(), elements.end());
		 

		 for (int i = 0; i < elements.size(); i++) {
			 inqueue.push(elements[i]);
		 }

		 cout << "\n����ǰ��";
		 queue<int> tempQueue = inqueue;
		 for (int i = 0; i < elements.size(); i++) {
			 cout << tempQueue.front() << " ";
			 tempQueue.pop();
		 }

		 mybucketSort(inqueue, outqueue);

		 cout << "\n�����";
		 while (!outqueue.empty()) {
			 cout << outqueue.front() << " ";
		
			 outqueue.pop();
		 }	
		 cout << "\n";


	

	 return 0;
 }
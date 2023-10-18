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
		if (Inqueue.front() == to_out) {//如果待排序队列队头元素等于to_out，直接进Outqueue
			Outqueue.push(Inqueue.front());
			Inqueue.pop();
			to_out++;
		}
		if (Inqueue.front() != to_out) {//如果待排序队列队头元素不等于to_out，进桶
			 int selected_bucket = -1;
			 for (int i = 0; i < buckets.size(); i++) {
				 if (Inqueue.front() > buckets[i].back()) {//如果待排序队列队头元素大于桶的队尾元素
					 if (selected_bucket == -1 || buckets[i].back() >= buckets[selected_bucket].back()) {
						 selected_bucket = i;//选择符合条件的桶里面，队尾元素最大的桶
						// break;
					 }
				 }
			 }
			 if (selected_bucket != -1) {
				 buckets[selected_bucket].push(Inqueue.front());//把Inqueue.front入选择好的队
			 }
			 else {
				
				 queue<T> new_bucket;
				 new_bucket.push(Inqueue.front());
				 buckets.push_back(new_bucket);//如果没有符合条件的桶，新建一个buket把元素入队
				
			 }

		 }
		 Inqueue.pop();
		}
	for (int i = 0; i < buckets.size(); i++) {
		while (!buckets[i].empty()) {
			if (buckets[i].front() == to_out) {//桶的队头元素有没有和to_out相等的
				Outqueue.push(buckets[i].front());
				buckets[i].pop();
				to_out++;
			}
			else {//桶的队头元素没有和to_out相等的
				vector<T> sorted_elements;//装所有在桶中的元素

				for (int i = 0; i < buckets.size(); i++) {//遍历所有桶
					while (!buckets[i].empty()) {
						sorted_elements.push_back(buckets[i].front());
						buckets[i].pop();
					}
				}

				// 对辅助容器中的元素排序
				sort(sorted_elements.begin(), sorted_elements.end());

				// 将排序后的元素依次加入到Outqueue中
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

		 cout << "\n排序前：";
		 queue<int> tempQueue = inqueue;
		 for (int i = 0; i < elements.size(); i++) {
			 cout << tempQueue.front() << " ";
			 tempQueue.pop();
		 }

		 mybucketSort(inqueue, outqueue);

		 cout << "\n排序后：";
		 while (!outqueue.empty()) {
			 cout << outqueue.front() << " ";
		
			 outqueue.pop();
		 }	
		 cout << "\n";


	

	 return 0;
 }
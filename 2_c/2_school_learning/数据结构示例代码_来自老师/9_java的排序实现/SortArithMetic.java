//这里是java的排序实现, 避免了c语言中指针的烦恼,有时间的话好好看看

public class SortArithMetic {
	/* 直接插入排序算法 */
	public int[] insertSort(int[] data) {
		for (int i = 1; i < data.length; i++) {
			// 判断无序区的第一个元素是否小于有序区的最后一个元素（即有序区最大的元素）
			if (data[i] < data[i - 1]) {
				int temp = data[i];
				int j = 0;
				// 将有序区的元素向后移动，为待插入元素留出位置
				for (j = i - 1; j >= 0 && temp < data[j]; j--) {
					data[j + 1] = data[j];
				}
				data[j + 1] = temp;// 将data[i]插入到有序区的位置上
			}
		}
		return data;
	}

	/* 希尔排序 */
	public int[] shellSort(int[] data) {// 希尔排序中的一趟排序，d为当前增量
		int i, j, temp, d;
		int increment=data.length/3;//增量的起始值取数字序列总长度的1/3
		for (int m = increment; m >=1; m--) {
			d = m;
			for (i = d; i < data.length; i++)
				// 将data[d+1．．n]分别插入各组当前的有序区
				if (data[i] < data[i - d]) {
					temp = data[i];
					j = i;
					do {// 查找data[i]的插入位置
						data[j] = data[j - d]; // 后移记录
						j = j - d;// 查找前一记录
						if (j - d < 0)
							break;
					} while (j > 0 && temp < data[j-d]);
					data[j] = temp; // 插入data[i]到正确的位置上
				}
		}
		return data;
	}

	// 直接选择排序
	public int[] selectSort(int[] data) {
		int k;// k记下目前找到的最小关键字所在的位置
		int temp;
		for (int i = 0; i < data.length - 1; i++) {// 做第i趟排序
			k = i;
			for (int j = i + 1; j < data.length; j++)
				if (data[j] < data[k])
					k = j;
			if (k != i) { // 交换
				temp = data[i];
				data[i] = data[k];
				data[k] = temp;
			}
		}
		return data;
	}
	// 堆排序
	public int[] heapSort(int[] data) {
		int tmp = 0;
		createHeap(data, 0, data.length - 1);
		for (int i = data.length - 1; i > 0; --i) {
			tmp = data[0];
			data[0] = data[i];
			data[i] = tmp;
			createHeap(data, 0, i - 1);
		}
		return data;
	}
	// 创建堆
	public void createHeap(int[] data, int low, int high) {
		if ((low < high) && (high < data.length)) {
			int j = 0;
			int k = 0;
			int tmp = 0;
			for (int i = high / 2; i >= low; --i) {
				tmp = data[i];
				k = i;
				j = 2 * k + 1;	
				while (j <= high) {
					if ((j < high) && (j + 1 <= high)
							&& (data[j] < data[j + 1])) {
						++j;
					}
					if (tmp < data[j]) {
						data[k] = data[j];
						k = j;
						j = 2 * k + 1;
					} else {
						break;
					}
				}
				data[k] = tmp;
			}
		}
	}

	

	// 冒泡排序
	public int[] bubbleSort(int[] data) {
		boolean exchange; // 交换标志
		int tmp;
		int n = data.length;
		for (int i = 1; i < n; i++) {// 最多做n-1趟排序
			exchange = false; // 本趟排序开始前，交换标志应为假
			for (int j = 0; j < n - i; j++)
				// 对当前无序区data[0..n-i]自下向上扫描
				if (data[j] > data[j + 1]) {// 交换记录
					tmp = data[j + 1];
					data[j + 1] = data[j];
					data[j] = tmp;
					exchange = true; // 发生了交换，故将交换标志置为真
				}
			if (!exchange) // 本趟排序未发生交换，提前终止算法
				break;
		}
		return data;
	}

	// 快速排序
	public int[] quickSort(int[] data){
		return quickSort(data,0,data.length-1);
	}
	public int[] quickSort(int[] data, int low, int high) {
		if (low > high)
			return null;
		int pivot = data[low];
		int i = low + 1;
		int j = high;
		int temp;
		while (i < j) {
			while ((i < j) && (pivot >= data[i])) {
				++i;
			}
			while ((j >= i) && pivot <= data[j]) {
				--j;
			}
			if (i < j) {
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
		if (low < j) {
			temp = data[low];
			data[low] = data[j];
			data[j] = temp;
		}
		quickSort(data, low, j - 1);
		quickSort(data, j + 1, high);
		return data;
	}

	// 归并排序
	public int[] mergeSort(int[] data) {
		int k = 1; // 归并增量
		while (k < data.length) {
			merge(data, k);
			k *= 2;
		}
		return data;
	}
	public void merge(int[] data, int len) {
		int m = 0; // 临时顺序表的起始位置
		int l1 = 0; // 第1个有序表的起始位置
		int h1; // 第1个有序表的结束位置
		int l2; // 第2个有序表的起始位置
		int h2; // 第2个有序表的结束位置
		int i = 0;
		int j = 0;
		// 临时表，用于临时将两个有序表合并为一个有序表
		int[] tmp = new int[data.length];
		// 归并处理
		while (l1 + len < data.length) {
			l2 = l1 + len; // 第2个有序表的起始位置
			h1 = l2 - 1; // 第1个有序表的结束位置
			// 第2个有序表的结束位置
			h2 = (l2 + len - 1 < data.length) ? l2 + len - 1 : data.length - 1;
			j = l2;
			i = l1;
			// 两个有序表中的记录没有排序完
			while ((i <= h1) && (j <= h2)) {
				// 第1个有序表记录的关键码小于第2个有序表记录的关键码
				if (data[i] <= data[j]) {
					tmp[m++] = data[i++];
				}
				// 第2个有序表记录的关键码小于第1个有序表记录的关键码
				else {
					tmp[m++] = data[j++];
				}
			}
			// 第1个有序表中还有记录没有排序完
			while (i <= h1) {
				tmp[m++] = data[i++];
			}
			// 第2个有序表中还有记录没有排序完
			while (j <= h2) {
				tmp[m++] = data[j++];
			}
			l1 = h2 + 1;
		}
		i = l1;
		// 原顺序表中还有记录没有排序完
		while (i < data.length) {
			tmp[m++] = data[i++];
		}
		// 临时顺序表中的记录复制到原顺序表，使原顺序表中的记录有序
		for (i = 0; i < data.length; ++i) {
			data[i] = tmp[i];
		}
	}

	// 基数排序
	public int[] radixSort(int[] data) {
		int k, l, power;
		RadixNode p, q;
		RadixNode[] head = new RadixNode[10];
		power = 1;
		// 首先确定排序的趟数;
		int max = data[0];
		for (int i = 1; i < data.length; i++) {
			if (data[i] > max) {
				max = data[i];
			}
		}
		int d = 0; // 关键码的位数
		// 判断位数;
		while (max > 0) {
			max /= 10;
			d++;
		}
		//进行d次分配和收集;
		for (int i = 0; i < d; i++) {
			if (i == 0)
				power = 1;
			else
				power = power * 10;
			for (int j = 0; j < 10; j++) {
				head[j] = new RadixNode();
			}
		    //分配数组元素;
			for (int j = 0; j < data.length; j++) {
				k = data[j] / power - (data[j] / (power * 10)) * 10;
				q = new RadixNode();
				q.data = data[j];
				q.next = null;
				p = head[k].next;
				if (p == null)
					head[k].next = q;
				else {
					while (p.next != null)
						p = p.next;
					p.next = q;
				}
			}
			//收集链表元素
			l = 0;
			for (int j = 0; j < 10; j++) {
				p = head[j].next;
				while (p != null) {
					data[l] = p.data;
					l++;
					p = p.next;
				}
			}
		}
		return data;
	}
    
	static class RadixNode {
		public int data; // 数据域
		public RadixNode next; // 引用域
	}

}

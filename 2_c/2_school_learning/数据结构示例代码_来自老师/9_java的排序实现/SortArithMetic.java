//������java������ʵ��, ������c������ָ��ķ���,��ʱ��Ļ��úÿ���

public class SortArithMetic {
	/* ֱ�Ӳ��������㷨 */
	public int[] insertSort(int[] data) {
		for (int i = 1; i < data.length; i++) {
			// �ж��������ĵ�һ��Ԫ���Ƿ�С�������������һ��Ԫ�أ�������������Ԫ�أ�
			if (data[i] < data[i - 1]) {
				int temp = data[i];
				int j = 0;
				// ����������Ԫ������ƶ���Ϊ������Ԫ������λ��
				for (j = i - 1; j >= 0 && temp < data[j]; j--) {
					data[j + 1] = data[j];
				}
				data[j + 1] = temp;// ��data[i]���뵽��������λ����
			}
		}
		return data;
	}

	/* ϣ������ */
	public int[] shellSort(int[] data) {// ϣ�������е�һ������dΪ��ǰ����
		int i, j, temp, d;
		int increment=data.length/3;//��������ʼֵȡ���������ܳ��ȵ�1/3
		for (int m = increment; m >=1; m--) {
			d = m;
			for (i = d; i < data.length; i++)
				// ��data[d+1����n]�ֱ������鵱ǰ��������
				if (data[i] < data[i - d]) {
					temp = data[i];
					j = i;
					do {// ����data[i]�Ĳ���λ��
						data[j] = data[j - d]; // ���Ƽ�¼
						j = j - d;// ����ǰһ��¼
						if (j - d < 0)
							break;
					} while (j > 0 && temp < data[j-d]);
					data[j] = temp; // ����data[i]����ȷ��λ����
				}
		}
		return data;
	}

	// ֱ��ѡ������
	public int[] selectSort(int[] data) {
		int k;// k����Ŀǰ�ҵ�����С�ؼ������ڵ�λ��
		int temp;
		for (int i = 0; i < data.length - 1; i++) {// ����i������
			k = i;
			for (int j = i + 1; j < data.length; j++)
				if (data[j] < data[k])
					k = j;
			if (k != i) { // ����
				temp = data[i];
				data[i] = data[k];
				data[k] = temp;
			}
		}
		return data;
	}
	// ������
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
	// ������
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

	

	// ð������
	public int[] bubbleSort(int[] data) {
		boolean exchange; // ������־
		int tmp;
		int n = data.length;
		for (int i = 1; i < n; i++) {// �����n-1������
			exchange = false; // ��������ʼǰ��������־ӦΪ��
			for (int j = 0; j < n - i; j++)
				// �Ե�ǰ������data[0..n-i]��������ɨ��
				if (data[j] > data[j + 1]) {// ������¼
					tmp = data[j + 1];
					data[j + 1] = data[j];
					data[j] = tmp;
					exchange = true; // �����˽������ʽ�������־��Ϊ��
				}
			if (!exchange) // ��������δ������������ǰ��ֹ�㷨
				break;
		}
		return data;
	}

	// ��������
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

	// �鲢����
	public int[] mergeSort(int[] data) {
		int k = 1; // �鲢����
		while (k < data.length) {
			merge(data, k);
			k *= 2;
		}
		return data;
	}
	public void merge(int[] data, int len) {
		int m = 0; // ��ʱ˳������ʼλ��
		int l1 = 0; // ��1����������ʼλ��
		int h1; // ��1�������Ľ���λ��
		int l2; // ��2����������ʼλ��
		int h2; // ��2�������Ľ���λ��
		int i = 0;
		int j = 0;
		// ��ʱ��������ʱ�����������ϲ�Ϊһ�������
		int[] tmp = new int[data.length];
		// �鲢����
		while (l1 + len < data.length) {
			l2 = l1 + len; // ��2����������ʼλ��
			h1 = l2 - 1; // ��1�������Ľ���λ��
			// ��2�������Ľ���λ��
			h2 = (l2 + len - 1 < data.length) ? l2 + len - 1 : data.length - 1;
			j = l2;
			i = l1;
			// ����������еļ�¼û��������
			while ((i <= h1) && (j <= h2)) {
				// ��1��������¼�Ĺؼ���С�ڵ�2��������¼�Ĺؼ���
				if (data[i] <= data[j]) {
					tmp[m++] = data[i++];
				}
				// ��2��������¼�Ĺؼ���С�ڵ�1��������¼�Ĺؼ���
				else {
					tmp[m++] = data[j++];
				}
			}
			// ��1��������л��м�¼û��������
			while (i <= h1) {
				tmp[m++] = data[i++];
			}
			// ��2��������л��м�¼û��������
			while (j <= h2) {
				tmp[m++] = data[j++];
			}
			l1 = h2 + 1;
		}
		i = l1;
		// ԭ˳����л��м�¼û��������
		while (i < data.length) {
			tmp[m++] = data[i++];
		}
		// ��ʱ˳����еļ�¼���Ƶ�ԭ˳���ʹԭ˳����еļ�¼����
		for (i = 0; i < data.length; ++i) {
			data[i] = tmp[i];
		}
	}

	// ��������
	public int[] radixSort(int[] data) {
		int k, l, power;
		RadixNode p, q;
		RadixNode[] head = new RadixNode[10];
		power = 1;
		// ����ȷ�����������;
		int max = data[0];
		for (int i = 1; i < data.length; i++) {
			if (data[i] > max) {
				max = data[i];
			}
		}
		int d = 0; // �ؼ����λ��
		// �ж�λ��;
		while (max > 0) {
			max /= 10;
			d++;
		}
		//����d�η�����ռ�;
		for (int i = 0; i < d; i++) {
			if (i == 0)
				power = 1;
			else
				power = power * 10;
			for (int j = 0; j < 10; j++) {
				head[j] = new RadixNode();
			}
		    //��������Ԫ��;
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
			//�ռ�����Ԫ��
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
		public int data; // ������
		public RadixNode next; // ������
	}

}

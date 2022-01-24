// �������
// https://programmers.co.kr/learn/courses/30/lessons/17681

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        int num1 = arr1[i];
        int num2 = arr2[i];
        string str = "";
        // arr1�� arr2�� i��° �ٿ� ���� ���� ��Ʈ����ũ�� �̿��ؼ� ��Ʈ Ȯ��
        for (int j = n - 1; j >= 0; j--) {
            if ((num1 & 1 << j) || (num2 & 1 << j)) str += '#'; // j��°�� ���� �ϳ��� ���� �ִٸ� (���������� 1 �̶��)
            else str += ' ';
        }
        answer.push_back(str);
    }
    return answer;
}
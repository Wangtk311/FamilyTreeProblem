#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct Person { //������Ԫ�鷽ʽ�洢ÿ����Ա����ÿ����Ա���������ԣ��������ֵܡ�����
	string name;
	Person* sibling;
	Person* child;
};

Person* find(Person* root, string name) {
	if (root == NULL) {
		return NULL;
	}
	if (root->name == name) {
		return root;
	}
	Person* p = find(root->sibling, name); // �����ֵ�
	if (p != NULL) {
		return p;
	}
	return find(root->child, name); // ���Һ���
}

void perfect(Person*& root) {
	cout << "���Ƶ�ǰ����:" << endl;
	cout << "������Ҫ������һ�����˵�����: ";
	string name;
	cin >> name;
	Person* p = find(root, name);
	if (p == NULL) {
		cout << "�������޴���! " << endl;
	}
	else {
		cout << "��ǰҪ������һ���ĳ�Ա������: " << p->name << endl;
		cout << "����������Ů����: ";
		int n;
		while (1) {
			cin >> n;
			if (cin.fail()) {
				cin.clear();
				while (getchar() != '\n');
				cin.clear();
				cout << "�����������������: ";
			}
			else if (n <= 0) {
				cout << "��������С�ڵ���0���Ƿ����֣�����������: ";
			}
			else {
				break;
			}
		}
		cout << "��������������Ů������: ";
		for (int i = 0; i < n; i++) {
			Person* child = new Person;
			cin >> child->name;
			child->sibling = NULL;
			child->child = NULL;
			if (p->child == NULL) {
				p->child = child;
			}
			else {
				Person* q = p->child;
				while (q->sibling != NULL) {
					q = q->sibling;
				}
				q->sibling = child;
			}
		}
		cout << "���Ƽ�ͥ�ɹ�! " << endl;
		cout << p->name << "����һ�������ǣ�";
		Person* q = p->child;
		while (q != NULL) {
			cout << q->name << " ";
			q = q->sibling;
		}
		cout << endl;
	}
}

void addchild(Person*& root) {
	cout << "��Ӽ�ͥ��Ա:" << endl;
	cout << "������Ҫ��Ӻ��ӵ��˵�����: ";
	string name;
	cin >> name;
	Person* p = find(root, name);
	if (p == NULL) {
		cout << "�������޴���! " << endl;
	}
	else {
		cout << "���뺢�ӵ�����: ";
		Person* child = new Person;
		cin >> child->name;
		child->sibling = NULL;
		child->child = NULL;
		if (p->child == NULL) {
			p->child = child;
		}
		else {
			Person* q = p->child;
			while (q->sibling != NULL) {
				q = q->sibling;
			}
			q->sibling = child;
		}
		cout << "��Ӻ��ӳɹ�! " << endl;
		cout << p->name << "����һ�������ǣ�";
		Person* q = p->child;
		while (q != NULL) {
			cout << q->name << " ";
			q = q->sibling;
		}
		cout << endl;
	}
}

void deletefamily(Person*& root) {
	cout << "��ɢĳ����ͥ:" << endl;
	cout << "������Ҫ��ɢ��ͥ���˵�����: ";
	string name;
	cin >> name;
	Person* p = find(root, name);
	if (p == NULL) {
		cout << "�������޴���! " << endl;
	}
	else if (p->child == NULL) {
		cout << "��������һ�����ӣ��޷���ɢ��ͥ! " << endl;
	}
	else {
		cout << "��ɢ��ͥ�ɹ�! " << endl;
		cout << "��ǰ" << p->name << "����һ��Ϊ�գ�";
		while (p->child != NULL) {
			Person* q = p->child;
			p->child = q->sibling;
			delete q;
		}
		cout << endl;
	}
}

void changename(Person*& root) {
	cout << "���ĳ�Ա����:" << endl;
	cout << "������Ҫ�������Ƶ��˵�����: ";
	string name;
	cin >> name;
	Person* p = find(root, name);
	if (p == NULL) {
		cout << "�������޴���! " << endl;
	}
	else {
		cout << "������ó�Ա����������";
		string newname;
		cin >> newname;
		p->name = newname;
		cout << "�������Ƴɹ�! " << endl;
		if (p->child == NULL) {
			cout << "��ǰ" << p->name << "����һ��Ϊ�գ�";
		}
		else {
			cout << "��ǰ" << p->name << "����һ�������ǣ�";
			Person* q = p->child;
			while (q != NULL) {
				cout << q->name << " ";
				q = q->sibling;
			}
		}
		cout << endl;
	}
}

void deletetree(Person*& root) {
	if (root == NULL) {
		return;
	}
	deletetree(root->sibling);
	deletetree(root->child);
	delete root;
}

int main() {
	cout << "******* ���׹���ϵͳ *******" << endl;
	cout << "============================" << endl;
	cout << "|  ��ѡ��ִ�еĲ�����      |" << endl;
	cout << "|  A.���Ƶ�ǰ����          |" << endl;
	cout << "|  B.��Ӽ�ͥ��Ա          |" << endl;
	cout << "|  C.��ɢĳ����ͥ          |" << endl;
	cout << "|  D.����ĳ����ͥ��Ա����  |" << endl;
	cout << "|  E.�˳�ϵͳ              |" << endl;
	cout << "============================" << endl;

	cout << "�����뽨������, ������������: ";
	Person* root = new Person;
	cin >> root->name;
	root->sibling = NULL;
	root->child = NULL;
	cout << "�˼��׵�������: " << root->name << endl;

	char optn = 0;
	while (true) {
		cout << "��ѡ��ִ�еĲ���: ";
		optn = _getch();
		switch (optn) {
			case 'A':
				cout << 'A' << endl;
				perfect(root);
				break;
			case 'B':
				cout << 'B' << endl;
				addchild(root);
				break;
			case 'C':
				cout << 'C' << endl;
				deletefamily(root);
				break;
			case 'D':
				cout << 'D' << endl;
				changename(root);
				break;
			case 'E':
				cout << 'E' << endl;
				cout << "�˳�ϵͳ!" << endl;
				cout << "ɾ�����׳ɹ���" << endl;
				deletetree(root);
				break;
			case 'a':
				cout << 'A' << endl;
				perfect(root);
				break;
			case 'b':
				cout << 'B' << endl;
				addchild(root);
				break;
			case 'c':
				cout << 'C' << endl;
				deletefamily(root);
				break;
			case 'd':
				cout << 'D' << endl;
				changename(root);
				break;
			case 'e':
				cout << 'E' << endl;
				cout << "�˳�ϵͳ!" << endl;
				cout << "ɾ�����׳ɹ���" << endl;
				deletetree(root);
				break;
			default:
				cout << "�����������������! " << endl;
				break;
		}
		if (optn == 'E' || optn == 'e') {
			break;
		}
	}
	return 0;
}
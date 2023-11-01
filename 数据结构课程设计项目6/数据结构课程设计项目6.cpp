#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct Person { //采用三元组方式存储每个成员，即每个成员有三个属性：姓名、兄弟、孩子
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
	Person* p = find(root->sibling, name); // 先找兄弟
	if (p != NULL) {
		return p;
	}
	return find(root->child, name); // 再找孩子
}

void perfect(Person*& root) {
	cout << "完善当前家谱:" << endl;
	cout << "请输入要创建下一代的人的姓名: ";
	string name;
	cin >> name;
	Person* p = find(root, name);
	if (p == NULL) {
		cout << "家谱中无此人! " << endl;
	}
	else {
		cout << "当前要创建下一代的成员姓名是: " << p->name << endl;
		cout << "请输入其子女人数: ";
		int n;
		while (1) {
			cin >> n;
			if (cin.fail()) {
				cin.clear();
				while (getchar() != '\n');
				cin.clear();
				cout << "输入错误，请重新输入: ";
			}
			else if (n <= 0) {
				cout << "输入数字小于等于0属非法数字，请重新输入: ";
			}
			else {
				break;
			}
		}
		cout << "请依次输入其子女的姓名: ";
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
		cout << "完善家庭成功! " << endl;
		cout << p->name << "的下一代孩子是：";
		Person* q = p->child;
		while (q != NULL) {
			cout << q->name << " ";
			q = q->sibling;
		}
		cout << endl;
	}
}

void addchild(Person*& root) {
	cout << "添加家庭成员:" << endl;
	cout << "请输入要添加孩子的人的姓名: ";
	string name;
	cin >> name;
	Person* p = find(root, name);
	if (p == NULL) {
		cout << "家谱中无此人! " << endl;
	}
	else {
		cout << "输入孩子的姓名: ";
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
		cout << "添加孩子成功! " << endl;
		cout << p->name << "的下一代孩子是：";
		Person* q = p->child;
		while (q != NULL) {
			cout << q->name << " ";
			q = q->sibling;
		}
		cout << endl;
	}
}

void deletefamily(Person*& root) {
	cout << "解散某个家庭:" << endl;
	cout << "请输入要解散家庭的人的姓名: ";
	string name;
	cin >> name;
	Person* p = find(root, name);
	if (p == NULL) {
		cout << "家谱中无此人! " << endl;
	}
	else if (p->child == NULL) {
		cout << "此人无下一代孩子，无法解散家庭! " << endl;
	}
	else {
		cout << "解散家庭成功! " << endl;
		cout << "当前" << p->name << "的下一代为空！";
		while (p->child != NULL) {
			Person* q = p->child;
			p->child = q->sibling;
			delete q;
		}
		cout << endl;
	}
}

void changename(Person*& root) {
	cout << "更改成员名称:" << endl;
	cout << "请输入要更改名称的人的姓名: ";
	string name;
	cin >> name;
	Person* p = find(root, name);
	if (p == NULL) {
		cout << "家谱中无此人! " << endl;
	}
	else {
		cout << "请输入该成员的新姓名：";
		string newname;
		cin >> newname;
		p->name = newname;
		cout << "更改名称成功! " << endl;
		if (p->child == NULL) {
			cout << "当前" << p->name << "的下一代为空！";
		}
		else {
			cout << "当前" << p->name << "的下一代孩子是：";
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
	cout << "******* 家谱管理系统 *******" << endl;
	cout << "============================" << endl;
	cout << "|  请选择执行的操作：      |" << endl;
	cout << "|  A.完善当前家谱          |" << endl;
	cout << "|  B.添加家庭成员          |" << endl;
	cout << "|  C.解散某个家庭          |" << endl;
	cout << "|  D.更改某个家庭成员姓名  |" << endl;
	cout << "|  E.退出系统              |" << endl;
	cout << "============================" << endl;

	cout << "首先请建立家谱, 输入祖先姓名: ";
	Person* root = new Person;
	cin >> root->name;
	root->sibling = NULL;
	root->child = NULL;
	cout << "此家谱的祖先是: " << root->name << endl;

	char optn = 0;
	while (true) {
		cout << "请选择执行的操作: ";
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
				cout << "退出系统!" << endl;
				cout << "删除家谱成功！" << endl;
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
				cout << "退出系统!" << endl;
				cout << "删除家谱成功！" << endl;
				deletetree(root);
				break;
			default:
				cout << "输入错误，请重新输入! " << endl;
				break;
		}
		if (optn == 'E' || optn == 'e') {
			break;
		}
	}
	return 0;
}
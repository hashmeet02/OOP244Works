int a = 10;
int b = 20;
int c = 30;
int* d[3] = { &a, &b, &c };
for (int i=	0; i < 3; i++) (*d[i])++;
for (int i=0; i < 3; i++) cout << *d[i] << " ";
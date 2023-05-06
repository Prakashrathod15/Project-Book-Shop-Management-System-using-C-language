
typedef struct book{
	int book_id;
	char book_name[20];
	char author_name[20];
	int price;
}book;
void add(book*,int);
void update(book*,int);
void display(book*,int);
void deletet(book*,int*);
void shortt(book*,int);
void max(book*,int);
void search(book*,int);

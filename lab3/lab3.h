typedef struct Data {
    char title[100];
    char author[50];
    int stockNumber;
    float wholesalePrice;
    float retailPrice;
    int wholesaleQuantity;
    int retailQuantity;
} Data;

typedef struct Node {
    Data book;
    struct Node *next;
} Node;

#define kTitleCharMax 100
#define kAuthorCharMax 50
#define kIntCharMax 10
#define kFloatCharMax 20

Node *readBooks(FILE *f);
void printBooks(Node *head, FILE *outputFile);
int countBooks(Node *head);
Node *insertBook(Node *head, Node *new);

Node *promptForUserOption(Node *head);

void totalRevenue(Node *head);
void totalWholesaleCost(Node *head);
void currentInvestment(Node *head);
void totalProfit(Node *head);
void totalNumSales(Node *head);
void averageProfitPerSale(Node *head);
void inStock(Node *head);
void outOfStock(Node *head);
Node *addBook(Node *head);
Node *removeBook(Node *head);

float revenue(Node *head);
float investment(Node *head);
float wholesaleCost(Node *head);
float profit(Node *head);
int sales(Node *head);

void scrubNewline(char *line);

/*DEBUG*/
void lab3Main(int argc, const char * argv[]);

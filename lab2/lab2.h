typedef struct DataNode {
    struct DataNode *next;
    float value;
} DataNode;

typedef struct DataSet {
    DataNode *head;
    int count;
} DataSet;

typedef struct SetNode {
    struct SetNode *next;
    DataSet *data;
} SetNode;

typedef struct SetList {
    SetNode *head;
    int count;
} SetList;

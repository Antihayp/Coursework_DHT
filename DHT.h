#ifndef DHT_H
#define DHT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEYSPACE 999

typedef struct List_node
{
	struct Node *first_node;
	int number_node;
} List_node;

typedef struct Node
{
	int id;
	int border;
	struct Node *right;
	struct Node *left;
	struct Hash_table *hash_table;
} Node;

typedef struct Hash_table
{
	int key;
	char *value;
	struct Hash_table *next;
	struct Hash_table *parent;
} Hash_table;

List_node *create_list_node(int);
void change_first_node(List_node*, Node*);
void info_first_node(List_node*);
void search_value(List_node*, char*);
void delete_dht(List_node*);
void delete_node(List_node*, int);
void add_node(List_node*);


void create_node(List_node*, int, int);
void add_node_to_list(Node*, Node*);
Node* search_key_in_node(List_node*, int, int);
void free_node(Node*);


void create_node_hash_table(Node*, int, char*);
int hash(char* value);
void add_value(List_node*, char*);
void add_node_hash_table(Node*);
Hash_table* search_key_in_table(Node*, int);
void free_hash_table(Hash_table*);
void delete_nht(Node*, Hash_table*);


void print_dht(List_node*);

#endif
#include "list.h"

Node_ptr create_node(value){
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}

List_ptr create_list(void){
  List *list = (List *)malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Status add_to_end(List *list, int value){
  Node *new_node = create_node(value);
  if(list->head == NULL){
    list->head = new_node;
  }
  else{
    list->last->next = new_node;
  }
  list->last = new_node;
  list->count++;
  return Success;
}

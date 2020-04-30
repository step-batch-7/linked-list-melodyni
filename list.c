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

Status add_to_end(List_ptr list, int value){
  Node_ptr new_node = create_node(value);
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

Status add_to_start(List_ptr list, int value){
  Node_ptr new_node = create_node(value);
  if(list->head == NULL){
    list->head= new_node;
    list->last = new_node;
  }
  else{
    new_node->next = list->head;
    list->head = new_node;
  }
  list->count++;
  return Success;
}

Status insert_at(List_ptr list, int value, int position){
  if(position< 0){
    return Failure;
  }
  if(position == 0){
    return add_to_start(list,value);
  }
  Node_ptr new_node = create_node(value);
  Node_ptr p_walk = list->head;
  while(--position > 0){
    if(p_walk == NULL){
      return Failure;
    }
    p_walk = p_walk->next;
  }
  new_node->next = p_walk->next;
  p_walk->next = new_node;
  return Success;
}

int search(List_ptr list,int element){
  Node_ptr p_walk = list->head;
  int index = 0;
  while(p_walk != NULL){
    if(p_walk->value == element){
      return index;
    }
    index++;
    p_walk = p_walk->next;
  }
  return -1;
}

Status add_unique(List_ptr list, int value){
  int status = search(list,value);
  if(status == -1){
    return add_to_end(list,value);
  }
  return Success;
}




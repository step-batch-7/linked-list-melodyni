#include "list.h"

Node_ptr create_node(int value){
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
  Node_ptr *node_to_set = &list->head;
  if(list->head != NULL){
    node_to_set = &list->last->next;
  }
  (*node_to_set) = new_node;
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
  if(position < 0){
    return Failure;
  }
  if(position == 0){
    return add_to_start(list,value);
  }
  if(position == list->count){
    return add_to_end(list,value);
  }
  Node_ptr new_node = create_node(value);
  Node_ptr p_walk = list->head;

  while(position > 1){
    if(p_walk == NULL){
      return Failure;
    }
    p_walk = p_walk->next;
    position--;
  }
  new_node->next = p_walk->next;
  p_walk->next = new_node;
  list->count++;
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

void display(List_ptr list){
  Node_ptr p_walk = list->head;
  while(p_walk != NULL){
    printf("%d",p_walk->value);
    p_walk = p_walk->next;
  }
} 

Status remove_from_start(List_ptr list){
  if(list->head == NULL){
    return Failure;
  }
  Node_ptr node_to_remove = list->head;
  list->head = list->head->next;
  free(node_to_remove);
  list->count--;
  return Success;
}

Status remove_from_end(List_ptr list){
  if(list->head == NULL){
    return Failure;
  }
  if(list->count == 1){
    return remove_from_start(list);
  }
  Node_ptr p_walk = list->head;
  while(p_walk->next->next != NULL){
    p_walk = p_walk->next;
  }
  list->last = p_walk;
  free(p_walk->next);
  p_walk->next = NULL;
  list->count--;
  return Success;
}

Status remove_at(List_ptr list, int position){
  if(position < 0 || position >= list->count){
    return Failure;
  }
  if(position == 0){
    return remove_from_start(list);
  }
  if(position == list->count-1){
    return remove_from_end(list);
  }
  Node_ptr p_walk = list->head;
  while(position > 1){
    p_walk = p_walk->next;
    position--;
  }
  Node_ptr node_to_remove = p_walk->next;
  p_walk->next = p_walk->next->next;
  free(node_to_remove);
  list->count--;  
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value){
  int position = search(list, value);
  return remove_at(list,position);
}

Status remove_all_occurrences(List_ptr list, int value){
  int position = search(list, value);
  while(position != -1){
    remove_at(list,position);
    position = search(list, value);
  }
  return Success;
}

Status clear_list(List_ptr list){
  Status status = Success;
  while(list->head != NULL){
    status =  remove_from_end(list);
  }
  return status;
}

void destroy_list(List_ptr list){
  clear_list(list);
  free(list);
}
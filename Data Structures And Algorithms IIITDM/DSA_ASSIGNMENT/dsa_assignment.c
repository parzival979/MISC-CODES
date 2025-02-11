#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct linked_list_node{
    int data;
    struct linked_list_node *next_node;
};


struct queue{
    struct linked_list_node *front;
    struct linked_list_node *rear;
};


struct junction_road{
    struct queue *queue;
    int number_of_cars_present;
    int number_of_cars_passed;
};


int maximum_cars_enter,maximum_cars_exit,emergency_service,number_of_roads;
int priority = -1,emergency_priority = -1;
int max_car_number;


struct queue *create_queue(void);
int queue_empty(struct queue *queue);
void enqueue_queue(struct queue *queue,int number);
int dequeue_queue(struct queue *queue);
void print_queue(struct queue *queue);
void road_vehicle_entry(struct junction_road *road);
void road_vehicle_remover(struct junction_road *road);
void priority_decider(struct junction_road *road);


int main(void){
    printf("PLEASE ENTER THE MAXIMUM VEHICLES THAT CAN BE ENTERED IN EACH ROAD\n");
    scanf("%d",&maximum_cars_enter);
    printf("PLEASE ENTER THE MAXIMUM VEHICLES THAT CAN BE REMOVED IN EACH ROAD\n");
    scanf("%d",&maximum_cars_exit);
    printf("PLEASE ENTER THE NUMBER THAT EMERGENCY SERVICE IS DIVISIBLE BY\n");
    scanf("%d",&emergency_service);
    printf("PLEASE ENTER THE NUMBER OF ROADS IN THE JUNCTION\n");
    scanf("%d",&number_of_roads);
    printf("PLEASE ENTER THE MAXIMUM CAR NUMBER IN THE ROADS\n");
    scanf("%d",&max_car_number);
    struct junction_road *road =(struct junction_road*)malloc(4 * sizeof(struct junction_road));
    for (int i = 0; i < number_of_roads; ++i) {
        (road + i)->queue = create_queue();
        (road + i)->number_of_cars_present = 0;
        (road + i)->number_of_cars_passed = 0;
    }
    srand(time(NULL));
    road_vehicle_entry(road);
    printf("THE SITUATION IN THE ROADS IS \n");
    for (int j = 0; j < number_of_roads; ++j) {
        print_queue((road + j)->queue);
        printf("THE NUMBER OF CARS IN ROAD %d IS %d\n",j+1,(road+j)->number_of_cars_present);
    }
    priority_decider(road);
    printf("THE PRIORITY AND EMERGENCY PRIORITY ARE %d and %d\n",priority+1,emergency_priority+1);
    int program_continuity;
    do{
        road_vehicle_remover(road);
        road_vehicle_entry(road);
        printf("PLEASE ENTER 1 IF YOU WANT TO SEE THE NEXT SITUATION ELSE 0\n");
        scanf("%d",&program_continuity);
        if(program_continuity == 1){
            printf("THE SITUATION IN THE ROADS IS \n");
            for (int j = 0; j < number_of_roads; ++j) {
                print_queue((road + j)->queue);
                printf("THE NUMBER OF CARS IN ROAD %d IS %d\n",j+1,(road+j)->number_of_cars_present);
            }
            priority_decider(road);
            printf("THE PRIORITY AND EMERGENCY PRIORITY ARE %d and %d\n",priority+1,emergency_priority+1);
        }
    }while(program_continuity);


}

struct queue *create_queue(void){
    struct queue *queue =(struct queue*)malloc(sizeof(struct queue));
    if(!queue)
        return NULL;
    queue->front = queue->rear = NULL;
    return queue;
}

int queue_empty(struct queue *queue){
    if(queue->front == NULL && queue->rear == NULL)
        return 1;
    else
        return 0;

}

void enqueue_queue(struct queue *queue,int number){
    struct linked_list_node *temp;
    temp =(struct linked_list_node*)malloc(sizeof(struct linked_list_node));
    temp->data = number;
    temp->next_node = NULL;
    if(queue_empty(queue)){
        queue->front = queue->rear = temp;
    }
    else{
        queue->rear->next_node = temp;
        queue->rear = temp;
    }
}

int dequeue_queue(struct queue *queue){
    struct linked_list_node *temp;
    if(queue_empty(queue)){
        printf("QUEUE EMPTY\n");
        return -1;
    }
    else{
        temp = queue->front;
        queue->front = queue->front->next_node;
        if(queue->front == NULL)
            queue->rear = NULL;
    }
    int number = temp->data;
    free(temp);
    return number;
}

void print_queue(struct queue *queue){
    struct linked_list_node *temp = queue->front;
    if(queue_empty(queue)) {
        printf("ROAD EMPTY\n");
        return;
    }
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next_node;
        if(temp != NULL)
            printf("->");
    }
    printf("\n");
}

void road_vehicle_entry(struct junction_road *road){
    for (int i = 0; i < number_of_roads; ++i) {
        int nos_cars = rand() % maximum_cars_enter;

        for (int j = 0; j < nos_cars ; ++j) {
            enqueue_queue((road + i)->queue,rand()%max_car_number);
            (road + i)->number_of_cars_present += 1;
        }
    }
}

void priority_decider(struct junction_road *road){
    int number_cars_passed_max = (road)->number_of_cars_passed;
    priority = 0;
    for (int i = 0; i < number_of_roads; ++i) {
       if((road + i)->number_of_cars_passed > number_cars_passed_max){
           number_cars_passed_max = (road + i)->number_of_cars_passed;
           priority = i;
       }
       struct linked_list_node *temp = (road + i)->queue->front;
        if(!(queue_empty((road + i)->queue))){
            while(temp != NULL){
                if((temp->data) % emergency_service == 0){
                    printf("EMERGENCY VEHICLE %d\n",temp->data);
                    emergency_priority = i;
                    return;
                }
                temp = temp->next_node;
            }
        }
    }
}

void road_vehicle_remover(struct junction_road *road){
    if(emergency_priority == -1 || emergency_priority == priority){
        printf("THE REMOVED VEHICLES ARE\n");
        int nos_removed = 0;
        for (int i = 0; i < maximum_cars_exit && !(queue_empty((road + priority)->queue)); ++i) {
            printf("%d->", dequeue_queue((road + priority)->queue));
            nos_removed += 1;
        }
        printf("\n");
        printf("THE NUMBER OF CARS REMOVED ARE %d\n",nos_removed);
        (road + priority)->number_of_cars_present -= nos_removed;
        for (int i = 0; i < number_of_roads; ++i) {
            (road + i)->number_of_cars_passed += nos_removed;
        }
        (road + priority)->number_of_cars_passed = 0;
        printf("\n");
        priority = -1;
        emergency_priority = -1;
    }
    else{
        printf("THE REMOVED VEHICLES ARE\n");
        int nos_removed = 0;
        while (((road + emergency_priority)->queue->front->data) % emergency_service != 0) {
            printf("%d->", dequeue_queue((road + emergency_priority)->queue));
            nos_removed += 1;
        }
        printf("%d->", dequeue_queue((road + emergency_priority)->queue));
        nos_removed += 1;
        printf("\n");
        printf("THE NUMBER OF VEHICLES REMOVED ARE %d\n",nos_removed);
        (road + emergency_priority)->number_of_cars_present -= nos_removed;
        for (int i = 0; i < number_of_roads; ++i) {
            (road + i)->number_of_cars_passed += nos_removed;
        }
        (road + emergency_priority)->number_of_cars_passed = 0;
        printf("\n");
        priority = -1;
        emergency_priority = -1;
    }

}




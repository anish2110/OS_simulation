#include<stdio.h> 

int main() 
{ 
  int count, n, j;
  int time, time_remaining;
  int flag = 0;
  int time_quantum = 10; 
  int waiting_time = 0;
  int turn_around_time = 0;
  int arrival_time[10], burst_time[10], remaining_time[10]; 
  
  printf("Enter the Total number of Process: \n"); 
  scanf("%d", &n); 
  
  time_remaining = n;
   
  for(count=0; count<n; count++) 
  { 
    printf("\nEnter Arrival Time(AT) and Burst Time(BT) for Process Number %d: ", count+1); 
    scanf("%d", &arrival_time[count]); 
    scanf("%d", &burst_time[count]); 
    
    remaining_time[count] = burst_time[count]; 
  } 
  
  printf("Enter Time Quantum:%d\t", time_quantum); 
  printf("\n\nProcess\t|Turn Around Time|Waiting Time\n\n");
   
  for(time=0, count=0; time_remaining!=0; ) 
  { 
    if(remaining_time[count]<=time_quantum && remaining_time[count]>0) 
    { 
      time += remaining_time[count]; 
      remaining_time[count] = 0; 
      flag = 1; 
    }
	 
    else if(remaining_time[count]>0) 
    { 
      remaining_time[count] -= time_quantum; 
      time += time_quantum; 
    }
	 
    if(remaining_time[count]==0 && flag==1) 
    { 
      time_remaining--; 
      
      printf("P[%d]\t|\t%d\t|\t%d\n", count+1, time-arrival_time[count], time-arrival_time[count]-burst_time[count]); 
      
      waiting_time += time-arrival_time[count] - burst_time[count]; 
      turn_around_time += time - arrival_time[count]; 
      flag = 0; 
    }
	 
    if(count==n-1) count=0; 
    else if(arrival_time[count+1]<=time) count++; 
    else count=0;
	 
  }
   
  printf("\nAverage Waiting Time= %f\n", waiting_time*1.0/n); 
  printf("Avg Turnaround Time = %f", turn_around_time*1.0/n); 

  return 0; 
}

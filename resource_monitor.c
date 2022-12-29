#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // Declare variables for storing system resource usage
  float cpu_usage, mem_usage, disk_usage;

  // Use the "top" command to get the current CPU usage
  FILE *fp;
  char buffer[1024];
  fp = popen("top -bn1 | grep '%Cpu'", "r");
  fgets(buffer, sizeof(buffer), fp);
  sscanf(buffer, "%*s %*s %*s %f", &cpu_usage);
  pclose(fp);

  // Use the "free" command to get the current memory usage
  fp = popen("free -m | grep 'Mem'", "r");
  fgets(buffer, sizeof(buffer), fp);
  sscanf(buffer, "%*s %*s %*s %f", &mem_usage);
  pclose(fp);

  // Use the "df" command to get the current disk usage
  fp = popen("df -h | grep '/dev/sda1'", "r");
  fgets(buffer, sizeof(buffer), fp);
  sscanf(buffer, "%*s %*s %*s %f", &disk_usage);
  pclose(fp);

  // Print the system resource usage to the console
  printf("CPU Usage: %.2f%%\n", cpu_usage);
  printf("Memory Usage: %.2f%%\n", mem_usage);
  printf("Disk Usage: %.2f%%\n", disk_usage);

  return 0;
}

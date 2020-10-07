#include <stdio.h>
int main(){

    float num1[3][4] = {{-2,1,4,2},{3,-3,3,1},{5,2,-2,1}};
    int line_num = 3, colum_num = 4;
    int line_count = 0,colum_count = 0 ,return_matrix_count = 0;

    float num_result[line_num][colum_num];
    float return_matrix[line_num];
    
    for(line_count = 1;line_count<line_num;line_count++)
    {
        int calc_count ;
        for (calc_count = 0;calc_count < line_count;calc_count++){
            float multiplication_num = num1[line_count][calc_count]/num1[calc_count][calc_count];      
            printf("%f\n",multiplication_num);
            for (colum_count = 0; colum_count < colum_num; colum_count++)
            {
                num_result[line_count][colum_count] = -multiplication_num *num1[calc_count][colum_count] +  num1[line_count][colum_count];
                num1[line_count][colum_count] = num_result[line_count][colum_count];
            }
            printf("\n");
            printf("%2.2f %2.2f %2.2f %2.2f\n",num1[0][0],num1[0][1],num1[0][2],num1[0][3]);
            printf("%2.2f %2.2f %2.2f %2.2f\n",num1[1][0],num1[1][1],num1[1][2],num1[1][3]);
            printf("%2.2f %2.2f %2.2f %2.2f\n",num1[2][0],num1[2][1],num1[2][2],num1[2][3]);
            printf("\n");
            printf("\n");

        }
    }
    
    return_matrix[3 - 1] = num1[3 - 1][colum_num-1] / num1[3 - 1][3 - 1];
    for(return_matrix_count = 2;return_matrix_count <=line_num ;return_matrix_count++)
    {
        int i = 0;
        for ( i = 1; i < return_matrix_count; i++)
        {
            num1[3 - return_matrix_count][colum_num-1] = num1[3 - return_matrix_count][colum_num-1] - (num1[3 - return_matrix_count][colum_num - (1 + i)]*return_matrix[3 - i]);
            printf("%2.4f   i= %d \n",num1[3 - return_matrix_count][colum_num-1],i);
        }
        return_matrix[3 - return_matrix_count]= num1[3 - return_matrix_count][colum_num-1] /num1[3 - return_matrix_count][3 - return_matrix_count];
    }
        
    printf("x1=%2.3f\n",return_matrix[0]);
    printf("x2=%2.3f\n",return_matrix[1]);
    printf("x3=%2.3f\n",return_matrix[2]);

    return 0;
}
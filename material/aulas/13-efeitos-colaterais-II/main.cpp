

int main(){

    double sum = 0.0;
    #pragma omp parallel for reduction(+:sum) private(r)
    for(int i = 0; i < num_steps; i++){
        #pragma omp critical{
            r = random();
            x = random();
            y = random();
        }

}
input_file = fopen("covid.txt");
output_file = fopen("output.txt", "w");

sequence = fscanf(input_file, "%s");

A = 0;
T = 0;
C = 0;
G = 0;

for i = 1:length(sequence)
    A = A + strcmp("A", sequence(i));   
    T = T + strcmp("T", sequence(i));   
    G = G + strcmp("G", sequence(i));   
    C = C + strcmp("C", sequence(i));   
end

fprintf(output_file,"A : %i\n", A);
fprintf(output_file,"T : %i\n", T);
fprintf(output_file,"C : %i\n", C);
fprintf(output_file,"G : %i\n", G);
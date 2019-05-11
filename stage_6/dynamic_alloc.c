			
			
void alloc(int p,FILE *xsm_file)
{
fprintf(xsm_file,"MOV R%d, \"Alloc\"\n",p);
fprintf(xsm_file,"PUSH R%d\n",p);
fprintf(xsm_file,"MOV R%d, 8\n",p);	// Allocating 8 words for each alloc call
fprintf(xsm_file,"PUSH R%d\n",p);
fprintf(xsm_file,"PUSH R0\n");
fprintf(xsm_file,"PUSH R0\n");
fprintf(xsm_file,"PUSH R0\n");
fprintf(xsm_file,"CALL 0\n");
fprintf(xsm_file,"POP R%d\n",p);
fprintf(xsm_file,"POP R0\n");
fprintf(xsm_file,"POP R0\n");
fprintf(xsm_file,"POP R0\n");
fprintf(xsm_file,"POP R0\n");
}			
void initialize(int p,FILE *xsm_file){
fprintf(xsm_file,"MOV R%d, \"Heapset\"\n",p);
fprintf(xsm_file,"PUSH R%d\n",p);
fprintf(xsm_file,"PUSH R0\n");
fprintf(xsm_file,"PUSH R0\n");
fprintf(xsm_file,"PUSH R0\n");
fprintf(xsm_file,"PUSH R0\n");
fprintf(xsm_file,"CALL 0\n");
fprintf(xsm_file,"POP R%d\n",p);
fprintf(xsm_file,"POP R0\n");
fprintf(xsm_file,"POP R0\n");
fprintf(xsm_file,"POP R0\n");
fprintf(xsm_file,"POP R0\n");
}
void freenode(int p,int q,FILE *xsm_file)
{
fprintf(xsm_file,"MOV R%d, \"Free\"\n",p);
fprintf(xsm_file,"PUSH R%d\n",p);
fprintf(xsm_file,"PUSH R%d\n",q);
fprintf(xsm_file,"PUSH R0\n");
fprintf(xsm_file,"PUSH R0\n");
fprintf(xsm_file,"PUSH R0\n");
fprintf(xsm_file,"CALL 0\n");
fprintf(xsm_file,"POP R%d\n",p);
fprintf(xsm_file,"POP R0\n");
fprintf(xsm_file,"POP R0\n");
fprintf(xsm_file,"POP R0\n");
fprintf(xsm_file,"POP R0\n");
}
void not(int l,int m,int p,FILE *xsm_file)
{
fprintf(xsm_file,"JZ R%d, L%d\n",p,l);
			fprintf(xsm_file,"MOV R%d, 0\n",p);
			fprintf(xsm_file,"JMP L%d\n",m);
			fprintf(xsm_file,"L%d:\n",l);
			fprintf(xsm_file,"MOV R%d, 1\n",p);
			fprintf(xsm_file,"L%d:\n",m);
}
void xos_call_write(int p,int q ,FILE *xsm_file)
{
fprintf(xsm_file,"MOV R%d, \"Write\"\n",p);
fprintf(xsm_file,"PUSH R%d\n",p);
fprintf(xsm_file,"MOV R%d, -2\n",p);
fprintf(xsm_file,"PUSH R%d\n",p);
//fprintf(xsm_file,"MOV R%d, %d\n",p,l);
fprintf(xsm_file,"PUSH R%d\n",q);
fprintf(xsm_file,"PUSH R0\n");
fprintf(xsm_file,"PUSH R0\n");
fprintf(xsm_file,"CALL 0\n");
fprintf(xsm_file,"POP R%d\n",p);
fprintf(xsm_file,"POP R0\n");
fprintf(xsm_file,"POP R0\n");
fprintf(xsm_file,"POP R0\n");
fprintf(xsm_file,"POP R0\n");

}
void xos_call_read(int p,int q,FILE *xsm_file)
{
fprintf(xsm_file,"MOV R%d, \"Read\"\n",p);
fprintf(xsm_file,"PUSH R%d\n",p);
fprintf(xsm_file,"MOV R%d, -1\n",p);
fprintf(xsm_file,"PUSH R%d\n",p);
//fprintf(xsm_file,"MOV R%d, %d\n",p,l);
fprintf(xsm_file,"PUSH R%d\n",q);
freeReg();
fprintf(xsm_file,"PUSH R0\n");
fprintf(xsm_file,"PUSH R0\n");
fprintf(xsm_file,"CALL 0\n");
fprintf(xsm_file,"POP R%d\n",p);
fprintf(xsm_file,"POP R0\n");
fprintf(xsm_file,"POP R0\n");
fprintf(xsm_file,"POP R0\n");
fprintf(xsm_file,"POP R0\n");
}

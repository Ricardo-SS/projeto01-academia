#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "infoAluno.h"

/* 
 * Autor: Francisco Ricardo dos Santos Silva
 * Matricula: 
 * Turma: 01
*/

//assunto; listas encadeadas e no
//contadador de horas gastas; 11,38h

//Estrutura com dados do aluno
struct InfoAluno{
    int mat;                     		//armazena matricula do aluno
    char nomeAluno[80];                 //armazena nome do aluno
    char sexoAluno[20];					//armazena sexo do aluno
    int idadeAluno;						//armazena idade do aluno
};

//Estrutura do No
struct no {
	infoAluno dado;
	struct no *prox;
};

//Estrutura de inicio do No
struct lista{
	No * inicio;
};


//Funcoes de mensagens de confirmacao
void nao_encontrado(){
    printf("\t*=======================================*\n");
    printf("\t|        Aluno nao encontrado!          |\n");
    printf("\t*=======================================*\n\n");
}
void lst_vazia (){
    printf("\n\t=======================================\n");
    printf("\t|           Lista vaizia!             |\n");
    printf("=======================================\n");
}
void aluno_deletado(){
    printf("\n\t*===========================================*\n");
    printf("\t|   SUCESSO: Registro do aluno deletado:    |\n");
    printf("\t*===========================================*\n\n");
}

//Funcao que vai ler os dados do estudante
void ler(infoAluno *pa){
	printf("\n\tMatriclula: ");
    scanf (" %d", &pa->mat); 
    printf("\tNone: ");
    scanf ("%s", pa->nomeAluno);
    printf("\tIdade: ");
    scanf (" %d", &pa->idadeAluno);
    printf("\tSexo: ");
    scanf("%s", pa->sexoAluno);
    
/*	
	printf("\n Sexo: Selecione uma das opcoes:");
    int sexo;
    
    printf("\n========================================\n");
	printf("|  1 - Maculino:						\n");
    printf("|  2 - Feminino:						\n");
    printf("|  3 - Outro:							\n");
    printf("=========================================\n");
    scanf (" %d", &sexo);
    if (sexo = 1) {
    	char * sex[]= "Masculino";
		pa->sexoAluno = sex;	
	}
	else if (sexo == 2) {
		//char sex[] = "Feminino";
		*pa->sexoAluno = sex;
	}
	else if (sexo == 3) {
		//char sex[] = "Outro";
		*pa->sexoAluno = sex;
	}
	else {
		printf ("Opcao Invalida.");
	}
*/	
        
}


//Sub manu, inserir alunos
void menu_iserir(){
	
	printf("\t:=============== MENU INSERIR ==============:\n");
	printf("\t|    9 - Inserir aluno no inicio:           |\n");
    printf("\t|   10 - Inserir aluno no fim:              |\n");
    printf("\t|   11 - Inserir apos matricula:            |\n");
    printf("\t|   12 - Inserir antes matricula:           |\n");
	printf("\t|   13 - Criar lista:                       |\n");
	printf("\t|    0 - Voltar:                            |\n");   
    printf("\t:===========================================:\n");
    printf("\t Selecione uma das opcoes: ");
}

void menu_delete (){
	printf("\t:=============== MENU EXCLUIR ==============:\n");
	printf("\t|    14 - Deletar no inicio:                |\n");
    printf("\t|    15 - Deletar no fim:                   |\n");
    printf("\t|    16 - Deletar por matricula:            |\n");
	printf("\t|    17 - Deletar apos:                     |\n");
    printf("\t|    18 - Deletar antes:                    |\n");
    printf("\t|    19 - Deletar lista:                    |\n");
	printf("\t|     0 - Voltar:                           |\n");
    printf("\t:===========================================:\n");
    printf("\t Selecione uma das opcoes: ");	
}

//menu de interacao com o usuarios

void menu(){
    //system("cls");
	printf("\t:=============== MENU INICIAL ==============:\n");
    printf("\t|    1 - Inserir aluno:                     |\n");
    printf("\t|    2 - Excluir aluno:                     |\n");
    printf("\t|    3 - Mostra lista:                      |\n");
    printf("\t|    4 - Pesquisar por matricula:           |\n");
	printf("\t|    5 - Alterar nome:                      |\n");
    printf("\t|    6 - Tamanho da lista:                  |\n");
    printf("\t|    7 - Salvar arquivo de dados:           |\n");
    printf("\t|    8 - Carregar de dados  arquivo:        |\n");
	printf("\t|    0 - Sair:                              |\n");
    printf("\t:===========================================:\n");
    printf("\t Selecione uma das opcoes: ");
}

//Funcao que iseri o novo aluno no inicio da lista

void inserir_inicio (Lista *plista, infoAluno dado) {
	No * novo = (No*) malloc(sizeof(No));
	novo->dado = dado;
	novo->prox = plista->inicio;
	plista->inicio = novo;
}

//Funcao para inserir aluno no fim da lista

void inserir_fim (Lista *plista, infoAluno dado){
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;
    if (plista->inicio ==NULL) {
        plista->inicio = novo;
    }
    else {
        No* pi;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox);
        pi->prox = novo;
    } 
}

//funcao responsavel por deletar no inicio da lista

void deletar_inicio(Lista *plista){
    if(plista->inicio == NULL){                 //se a lista estiver vazia, retorna a mensagem abaixo
        lst_vazia ();
    }

    /*se existir elementos na lista o primeiro elemento sera deletado e o inicio da lista 
    recebe o proximo elemento que sera o novo inicicio*/
    else {
        No* pi = plista->inicio;
        plista->inicio = pi->prox;
        aluno_deletado();
        free(pi);                               //libera a memoria do pi
    }
}

//Funcao para deletar no fim da lista

void deletar_fim(Lista *plista){
    if(plista->inicio == NULL){
        lst_vazia (); 
    }
    
    else if (plista->inicio->prox == NULL) {
        No* pi = plista->inicio;         		//cria um ponteiro de No pi que aponta para o inicio da lista
        plista->inicio = NULL;                  //define o inicio como NULL
        aluno_deletado();
        free(pi);                               //libera o No que ateriormente era o inicio
        
    }
    else {
        No* pi;                         		//cria um estrutura de No 
        No* pa;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox) {
            pa = pi;                            //atribui a pa o valor de pi
        }
        pa->prox = NULL;                        //atribui a pa->prox o valor nulo
        aluno_deletado();
        free(pi);                               //liberar memoria do ponteiro pi
    }

}

//deletar por matricula

void deletar_mat(Lista * plista, int mat){
    
    if(plista->inicio == NULL){                     //inicio igual a NULL
        lst_vazia (); 
    }
    
    else if(plista->inicio->dado.mat == mat) {      //No se encontra no inicio
        No* pi = plista->inicio;
        plista->inicio = pi->prox;
        aluno_deletado();
        free(pi);
    }

    else if (plista->inicio->prox == NULL) {        //Lista tem um unico no e matricula nao existe
        if (plista->inicio->dado.mat != mat){
            nao_encontrado();
        }

    }
    else {                                          //lista com multiplos No, o valor existe
        No* pa;
        No* pi;
        for (pi = plista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox) {
            pa = pi;
        }
        if (pi == NULL) {
            nao_encontrado();
        }
        else {
            pa->prox = pi->prox;
            aluno_deletado();
            free(pi);
        }
    }
    
}

//deletar apos uma matricula especifica

void deletar_apos (Lista * plista, int mat){
    No* pa;
    No* pi;
    for (pa = plista->inicio; pa != NULL && pa->dado.mat != mat; pa = pa->prox);
    if (pa == NULL) {
        nao_encontrado();
    }
    else if (pa->prox == NULL) {
        nao_encontrado();
    }
    else {
        pi = pa->prox;
        pa->prox = pi->prox;
        free(pi);
        aluno_deletado();
    }
}

//funcao deletar antes de uma matricula especifica
void deletar_antes (Lista *plista, int mat) {
    if (plista->inicio == NULL){                      //inicio igual a NULL: lista vazia
        lst_vazia ();
    }

    else { 
        No* paa = (NULL);
        No* pa = (NULL);
        No* pi; 
        for (pi = plista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox) {
            paa = pa;
            pa = pi;
        }

        //multiplos intes: No existe
        //multiplos intes: No existe 
        if (pi == NULL) { 
            nao_encontrado();
        } 

        //No inicial igual ao No pesquisado
        else if (pa == NULL) { 
            nao_encontrado();
        }
        //O segundo no eh igual ao valor pesquisado
        else if (paa == NULL) {
            plista->inicio = pi;
            free(pa);
        }
        
        else {
            aluno_deletado();
            paa->prox = pi;
            free(pa);
            
        } 
    }
}

//deletar toda a lista

void deletar_lista (Lista *plista) {
    No* pi;
    while (plista->inicio != NULL) {
        pi = plista->inicio;
        plista->inicio = pi->prox;
        
        free(pi);
    }
    printf ("\n\t>>>>>>>>>> Lista completa deletada <<<<<<<<<<\n\n");
    
}

//Funcao de mostra lista de alunos cadastrado

void mostrar(Lista lista) {
    No * pi;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("\t|  [%d]: %s\n" , pi->dado.mat, pi->dado.nomeAluno);
        printf("\t|     : %d Anos :  Sexo:%s\n", pi->dado.idadeAluno, pi->dado.sexoAluno);
        printf("\t|------------------------------------\n");
    }  
}

//Funcao de pesquisar por matricula

No* pesquisar (Lista lista, int mat) {
    No* pi;
    for (pi = lista.inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox);
    return pi;
}

//Funcao alterar nome
void alterar_nome(Lista *plista, int mat, char nome[]){
    No* pi = pesquisar(*plista, mat);
    if (pi == NULL) {
        lst_vazia ();
    }
    else {
        strcpy (pi->dado.nomeAluno, nome);
        printf("\t>>>>> Nome alterado com sucesso: <<<<<\n");
    }

}

//Funcao mostrar tamanho da lista.
int tamanho_lista(Lista lista) {
    No* pi;
    int cont = 0;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        cont++;
    }
    return cont;
    
}

//Funcao de criar lista com um numero n de alunos

Lista criar_lista(int n) {
    Lista lista;
    lista.inicio = NULL;
    int i;
    for (i = 0; i < n; i++){
        infoAluno a;
        ler(&a);
        inserir_fim(&lista, a);
    }
    return lista;
}

//Funcao ordenar lista

void ordenar_lista(Lista *plista) {
    No* pi;
    No* pj;
    No* pfim = NULL;
    if (plista->inicio == NULL) {
        return;
    }
    for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox) {
        for (pj = plista->inicio; pj->prox != pfim; pj = pj->prox) {
            if (pj->dado.mat > pj->prox->dado.mat) {
                infoAluno temp = pj->dado;
                pj->dado = pj->prox->dado;
                pj->prox->dado = temp;
            }
        }
        pfim = pj;
    }
}

//ler arquivos de um arquivo

Lista ler_arquivo () {
    Lista lista;
    lista.inicio = NULL;
    FILE *file = fopen("./bdados.b", "rb");
    infoAluno a;
    while (fread(&a, sizeof(infoAluno), 1, file)) {
        inserir_fim(&lista, a);
    }
    fclose(file);
    return lista;
}

//Funcao salvar lista em binario

void salvar_arquivo (Lista lista) {
    FILE *file = fopen ("./bdados.b", "wb");
    No* pi;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        fwrite(&pi->dado, sizeof(infoAluno), 1, file);
    }
    fclose (file);
}

//Funcao que vai inserir um aluno após o No

No* inserir_apos (Lista *plista, infoAluno dado, int mat) {
    No * pi;
    for (pi = plista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox);
    if (pi == NULL) {
        return pi;
    }
    else {
        No *novo = (No *) malloc(sizeof(No));
        novo->dado = dado;
        novo->prox = pi->prox;
        pi->prox = novo;
        return pi;
    }
}

//Funcao para inserir antes do No

No* inserir_antes(Lista *plista, infoAluno dado, int mat) {
    if (plista->inicio == NULL) {
        return NULL;
    }
    else if (plista->inicio->dado.mat == mat) {
        No* novo = (No*) malloc(sizeof(No));
        novo->dado = dado;
        novo->prox = plista->inicio;
        plista->inicio = novo;
    }
    else {
        No* pi;
        for (pi = plista->inicio; pi->prox != NULL && pi->prox->dado.mat != mat; pi = pi->prox);
        if (pi->prox == NULL) {
            return NULL;
        }
        else {
            No *novo = (No*) malloc(sizeof(No));
            novo->dado = dado;
            novo->prox = pi->prox;
            pi->prox = novo;
            return pi;
        }
    }
}

//programa pricipal

void main_infoAluno() {
	Lista lista;
	lista.inicio = NULL;	                //inicia a lista vazia
    int op;					                //armazena a opcao digitada
	menu();
    scanf ("%d", &op);                      //ler e armazena a opcao digitada no menu

    while(op != 0){			                //enquanto a opcao for diferente de 2 o programa continua em execursao
        
        //menu principal
        if (op == 3) {
            printf("\n\t==== Lista de alunos cadastrados ====\n");
            printf("\t|  MAT: NOME \n");
            printf("\t|------------------------------------\n");
            ordenar_lista(&lista);
            mostrar(lista);
            printf("\t=========== Fim da Lista ============\n\n");
        }
        if (op == 4) {
            int mat;
            printf("Informe a matricula: ");
            scanf("%d", &mat);
            No * pi = pesquisar(lista, mat);
            if (pi != NULL) {
                printf("\t========== Aluno encontrado ===========\n");
                printf("\t|    %d : %s\n", pi->dado.mat, pi->dado.nomeAluno);
                printf("\t=======================================\n");
            }
            else {
                nao_encontrado();
            }
        }

        if (op == 5) {
            int mat;
            printf("Informe a matricula que deseja alterar o nome: ");
            scanf("%d", &mat);
            printf("Informe o NOVO nome do aluno: ");
            char nome[81];
            scanf("%s", &nome);
            alterar_nome(&lista, mat, nome);
        }

        if (op == 6) {
            int tam = tamanho_lista(lista);
            printf("\t=======================================\n");
            printf("\t\tA lista possui %d registros:\n", tam);
            printf("\t=======================================\n\n");
        }

        if (op == 7) {
        	ordenar_lista(&lista);
            salvar_arquivo (lista);
            printf("\t=======================================\n");
            printf("\t>>>>>  Arquivo salvo com sucesso  <<<<<\n");
            printf("\t=======================================\n\n");
        }

        if (op == 8) {
            lista = ler_arquivo();
            printf("\t=======================================\n");
            printf("\t>>>> Arquivo caregado com sucesso  <<<<\n");
            printf("\t=======================================\n\n");
        }
    
        //função de sub menu iserir aluno
        if (op == 1) {       
            menu_iserir();
            scanf("%d", &op);
            
			if (op == 9){
				infoAluno a;
				ler(&a);		                //chama a funcao ler que pedira os dados do aluno
				inserir_inicio(&lista, a);		//chama a funcao inserir_inicio que ira inceri o aluno no inicio da lista
			}
	        else if (op == 10) {
	            infoAluno a;
	            ler(&a);
	            inserir_fim(&lista, a);
	        
	        }
	        else if (op == 11) {
	            infoAluno a;
	            //ler (&a);
	            int mat;
	            printf("Informe a matricula para inserir apos: ");
	            scanf("%d", &mat);
				ler (&a); 
	            No * pi = inserir_apos(&lista, a, mat);
	            if (pi == NULL) {
	                printf("\n\t=======================================\n");
	                printf("\t|   Nao foi possivel inserir o aluno! \n");
	                printf("\t=======================================\n");
	            }
        	}
	        else if (op == 12) {
	            infoAluno a;
	            //ler(&a);
	            printf("Informe a matricula para inserir antes: ");
	            int mat;
	            scanf("%d", &mat);
	            ler(&a);
	            No * pi = inserir_antes(&lista, a, mat);
	            if (pi == NULL) {
	                printf("\n\t=======================================\n");
	                printf("\t|    Nao foi possivel inserir aluno: \n");
	                printf("\t=======================================\n");
	            }
	        }
	        else if (op == 13) {
	            int n;
	            printf("Informe a quantidades de alunos para cadastrar: ");
	            scanf("%d", &n);
	            lista = criar_lista(n);
	            printf("\t=======================================\n");
	            printf("\t>>>>   Lista criada com sucesso   <<<<<\n");
	            printf("\t=======================================\n\n");
	        }

	        
			
		}
		// Sub menu excluir aluno 
		if (op == 2) {       
            menu_delete();
            scanf("%d", &op);
            
			if (op == 14) {
    		deletar_inicio(&lista);
	        }
	
	        else if (op == 15) {
	            deletar_fim(&lista);   
	        }
	
	        else if (op == 16) {
	            int mat;
	            printf("Informe a matricula: ");
	            scanf("%d", &mat);
	            deletar_mat(&lista, mat);
	        }
	
	        else if (op == 17) {
	            int mat;
	            printf("A matricula seguinte a digitada sera excluida: ");
	            printf("Informe a matricula: ");
	            scanf("%d", &mat);
	            deletar_apos(&lista, mat);
	        }
	
	        else if (op == 18) {
	            int mat;
	            printf("A matricula anterior a digitada sera excluida:\n ");
	            printf("Informe a matricula: ");
	            scanf("%d", &mat);
	            deletar_antes (&lista, mat);
	        }
	
	        else if (op == 19) {       
	            deletar_lista (&lista);
	        }

		} 
		

        /*chama o menu novamente para saber se o usuario quer 
        inserir outo aluno ou finalizar o programa.*/
		menu();				                
    	scanf("%d", &op);	                //recebe a opcao digitada
	}
    printf ("\nPrograma finalizado...\n");
    
}
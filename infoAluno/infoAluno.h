typedef struct InfoAluno infoAluno;

typedef struct no No;

typedef struct lista Lista;

//menu de interacao com o usuarios
void menu();

//Funcoes de mensagens de confirmacao
void nao_encontrado();
void lst_vazia ();
void aluno_deletado();

//Função de sub menus
void menu_delete();
void menu_iserir();


//Funcao que vai ler os dados do estudante
void ler(infoAluno *pa);

//Funcao que inseri o novo aluno no inicio da lista
void inserir_inicio (Lista *plista, infoAluno dado);

//Funcao para inserir aluno no fim da lista
void inserir_fim (Lista *plista, infoAluno dado);

//funcao responsavel por deletar no inicio da lista
void deletar_inicio(Lista *plista);

//Funcao para deletar no fim da lista
void deletar_fim(Lista *plista);

//deletar por matricula
void deletar_mat(Lista * plista, int mat);

//deletar apos
void deletar_apos (Lista * plista, int mat);

//funcao deletar antes
void deletar_antes (Lista *plista, int mat);

//deletar toda a lista
void deletar_lista (Lista *plista);

//Funcao de mostra lista de alunos cadastrado
void mostrar(Lista lista);

//Funcao de pesquisar por matricula
No* pesquisar (Lista lista, int mat);

//Funcao alterar nome
void alterar_nome(Lista *plista, int mat, char nome[]);

//Funcao mostrar tamanho da lista.
int tamanho_lista(Lista lista);

//Funcao de criar lista com um numero n de alunos
Lista criar_lista(int n);

//Funcao ordenar lista
void ordenar_lista(Lista *plista);

//ler arquivos de um arquivo
Lista ler_arquivo ();

//Funcao salvar lista em binario
void salvar_arquivo (Lista lista);

//Funcao que vai inserir um aluno após o No
No* inserir_apos (Lista *plista, infoAluno dado, int mat);

//Funcao para inserir antes do No
No* inserir_antes(Lista *plista, infoAluno dado, int mat);

void main_infoAluno();


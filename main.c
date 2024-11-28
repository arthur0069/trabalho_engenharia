#include <stdio.h>
#include <string.h>

#define MAX_TAREFAS 100
#define TAMANHO_NOME 100

typedef struct
{
    int id;
    char nome[TAMANHO_NOME];
    int concluida;
} Tarefa;

Tarefa tarefas[MAX_TAREFAS];
int contadorTarefas = 0;

void criarTarefa()
{
    if (contadorTarefas >= MAX_TAREFAS)
    {
        printf("Limite de tarefas atingido!\n");
        return;
    }

    Tarefa novaTarefa;
    novaTarefa.id = contadorTarefas + 1;
    printf("Digite o nome da tarefa: ");
    getchar();
    fgets(novaTarefa.nome, TAMANHO_NOME, stdin);
    novaTarefa.nome[strcspn(novaTarefa.nome, "\n")] = '\0';
    novaTarefa.concluida = 0;

    tarefas[contadorTarefas++] = novaTarefa;
    printf("Tarefa criada com sucesso!\n");
}
void listarTarefas()
{
    if (contadorTarefas == 0)
    {
        printf("Nenhuma tarefa disponível.\n");
        return;
    }

    for (int i = 0; i < contadorTarefas; i++)
    {
        printf("ID: %d | Nome: %s | Concluída: %s\n",
               tarefas[i].id, tarefas[i].nome, tarefas[i].concluida ? "Sim" : "Não");
    }
}
void atualizarTarefa()
{
    int id;
    printf("Digite o ID da tarefa que deseja atualizar: ");
    scanf("%d", &id);

    for (int i = 0; i < contadorTarefas; i++)
    {
        if (tarefas[i].id == id)
        {
            printf("Digite o novo nome da tarefa: ");
            getchar();
            fgets(tarefas[i].nome, TAMANHO_NOME, stdin);
            tarefas[i].nome[strcspn(tarefas[i].nome, "\n")] = '\0';

            printf("A tarefa foi concluída? (1 para Sim, 0 para Não): ");
            scanf("%d", &tarefas[i].concluida);

            printf("Tarefa atualizada com sucesso!\n");
            return;
        }
    }

    printf("Tarefa com ID %d não encontrada.\n", id);
}
void deletarTarefa()
{
    int id;
    printf("Digite o ID da tarefa que deseja deletar: ");
    scanf("%d", &id);

    for (int i = 0; i < contadorTarefas; i++)
    {
        if (tarefas[i].id == id)
        {
            for (int j = i; j < contadorTarefas - 1; j++)
            {
                tarefas[j] = tarefas[j + 1];
            }
            contadorTarefas--;
            printf("Tarefa deletada com sucesso!\n");
            return;
        }
    }

    printf("Tarefa com ID %d não encontrada.\n", id);
}
int main()
{
    int opcao;

    do
    {
        printf("\n--- Gerenciamento de Tarefas ---\n");
        printf("1. Criar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Atualizar Tarefa\n");
        printf("4. Deletar Tarefa\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            criarTarefa();
            break;
        case 2:
            listarTarefas();
            break;
        case 3:
            atualizarTarefa();
            break;
        case 4:
            deletarTarefa();
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida.\n"); // teste
            
        }
    }
    while (opcao != 5);

    return 0;
}

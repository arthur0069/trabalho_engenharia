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
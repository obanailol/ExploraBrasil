#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POSTS 10
#define MAX_COMENTARIOS 5

typedef struct {
    char texto[200];
} Comentario;

typedef struct {
    char titulo[100];
    char descricao[300];
    int likes;
    Comentario comentarios[MAX_COMENTARIOS];
    int total_comentarios;
} Post;

Post posts[MAX_POSTS];
int total_posts = 0;

void criar_post() {
    if (total_posts >= MAX_POSTS) {
        printf("Limite de posts atingido.\n");
        return;
    }

    printf("Titulo do post: ");
    fgets(posts[total_posts].titulo, sizeof(posts[total_posts].titulo), stdin);

    printf("Descricao do post: ");
    fgets(posts[total_posts].descricao, sizeof(posts[total_posts].descricao), stdin);

    posts[total_posts].likes = 0;
    posts[total_posts].total_comentarios = 0;

    printf("Post criado com sucesso!\n\n");
    total_posts++;
}

void listar_posts() {
    if (total_posts == 0) {
        printf("Nenhum post criado ainda.\n\n");
        return;
    }

    for (int i = 0; i < total_posts; i++) {
        printf("Post #%d\n", i + 1);
        printf("Titulo: %s", posts[i].titulo);
        printf("Descricao: %s", posts[i].descricao);
        printf("Likes: %d\n", posts[i].likes);
        printf("Comentarios:\n");
        for (int j = 0; j < posts[i].total_comentarios; j++) {
            printf("  - %s", posts[i].comentarios[j].texto);
        }
        printf("\n");
    }
}

void dar_like() {
    int id;
    printf("Digite o numero do post para dar like: ");
    scanf("%d", &id);
    getchar(); // limpar buffer

    if (id < 1 || id > total_posts) {
        printf("Post invalido.\n\n");
        return;
    }

    posts[id - 1].likes++;
    printf("Like adicionado ao post #%d!\n\n", id);
}

void comentar_post() {
    int id;
    printf("Digite o numero do post para comentar: ");
    scanf("%d", &id);
    getchar(); // limpar buffer

    if (id < 1 || id > total_posts) {
        printf("Post invalido.\n\n");
        return;
    }

    if (posts[id - 1].total_comentarios >= MAX_COMENTARIOS) {
        printf("Limite de comentarios atingido para este post.\n\n");
        return;
    }

    printf("Digite seu comentario: ");
    fgets(posts[id - 1].comentarios[posts[id - 1].total_comentarios].texto, 200, stdin);
    posts[id - 1].total_comentarios++;

    printf("Comentario adicionado!\n\n");
}

int main() {
    int opcao;

    do {
        printf("===== MENU =====\n");
        printf("1. Criar post\n");
        printf("2. Listar posts\n");
        printf("3. Dar like\n");
        printf("4. Comentar post\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1: criar_post(); break;
            case 2: listar_posts(); break;
            case 3: dar_like(); break;
            case 4: comentar_post(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n\n");
        }
    } while (opcao != 0);

    return 0;
}

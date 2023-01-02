#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

int EncerrarCompra()
{
  char retornoMenu;
  system("cls");
  printf("========Compra encerrada!========");
  printf("\nDigite algum valor para encerrar a aplicação: ");
  scanf("%c", &retornoMenu);
  exit(0);
}

//escreve as mensagens do sistema
void Mensagem(int x)
{
  switch (x)
  {
  case 0:
    //menu
    printf("========Sistema de compras========");
    printf("\n\n 1- Realizar Compra");
    printf("\n 2- Créditos ");
    printf("\n 3- Sair do sistema");
    printf("\n\n Digite a opção desejada: ");
    break;
    
  case 1:
    //créditos
    printf(" Desenvolvido por Israel Andreotti Curtinaz @2022");
    printf("\n\n Digite 0 para voltar: ");
    break;

  case 2:
    printf("\n Deseja continuar com a compra? ");
    printf("\n 1- Sim");
    printf("\n 2- Não");
    printf("\n Digite a opção desejada: ");
    break;

  case 3:
    //modalidade de pagamento
    printf("\n========Modalidades de pagamento========\n");
    printf(" 1 - à vista..............desconto de 2.5%% sobre o preço de tabela\n");
    printf(" 2 - 2 até 5x.............preço de tabela sem desconto ou acréscimo\n");
    printf(" 3 - 6 até 10x............juros de 6%% sobre o preço de tabela\n");
    printf(" 4 - 11 até 15x...........juros de 13%% sobre o preço de tabela\n");
    printf("\n\n Digite o número de parcelas desejada: ");
    break;
  

   default:
    //Erro
    printf(" ERRO: Opção não existente!");
    break;
  }
}

void Comprar()
{

  char nome[255];
  char cpf[25];

  int nProdutos;
  float ptProdutos = 0;
  float pUnitario[255];

  int parcelas;
  float vParcelas;
  float pFinal;

  int modalidade;


  system("cls");

  printf(" Digite o nome do cliente: ");
  scanf("%s", &nome);

  printf(" Digite o CPF do cliente: ");
  scanf("%s", &cpf);

  printf(" Digite o número de produtos a serem comprados: ");
  scanf("%d", &nProdutos);

  printf("\n==========================================\n");

  for(int i = 0; i < nProdutos; i++) {

    printf(" Digite o preço do produto: R$ ");
    scanf("%f", &pUnitario[i]);

    ptProdutos = ptProdutos + pUnitario[i];

  }

  printf("\n O valor total dos produtos é de R$ %.2lf\n", ptProdutos);

  printf("\n==========================================\n");

  int x;
  x = 1;
  
  //Selecionar modalidade de pagamento
  int y;
  y = 1;
  while(y == 1){ 
    Mensagem(3);
    scanf("%d", &parcelas);

    if(parcelas > 0 && parcelas <= 15)
    {
      if(parcelas == 1)
      {
        pFinal = ptProdutos - (ptProdutos/100 * 2.5); 
        modalidade = 0;
      }
      else if(parcelas > 1 && parcelas < 6)
      {
        pFinal = ptProdutos;
        modalidade = 1;
      }
      else if(parcelas > 5 && parcelas < 11)
      {
        pFinal = ptProdutos + (ptProdutos/100 * 6);
        modalidade = 2;
      }
      else if(parcelas > 10 && parcelas < 16)
      {
        pFinal = ptProdutos + (ptProdutos/100 * 13);
        modalidade = 3;
      }
      y = 0;
      system("cls");
    }
    else
    {
      printf("\n\n ERRO! Escolha entre 1 à 15 parcelas, de acordo com as opções a cima.");
      system("cls");
    }
  }

  ///calcula o valor da parcela
  vParcelas = pFinal/((float)parcelas);

  printf("========Resumo da Compra========\n");
  printf("\n Cliente: %s", nome);
  printf("\n CPF: %s", cpf);
  printf("\n Preço de Tabela: %.2f", ptProdutos);
  printf("\n Número de parcelas: %d", parcelas);
  
  switch (modalidade)
  {
    case 0:
       printf("\n Compra a vista com 2,5%% de desconto.");
      break;
    case 1:
      printf("\n Compra a prazo em %d pelo preço de tabela.", parcelas);
      break;
    case 2:
      printf("\n Compra a prazo em %dx com 6%% de juros.", parcelas);
      break;
    case 3:
      printf("\n Compra a prazo em %d com 13%% de juros.", parcelas);
      break;
  }
  printf("\n Preco total: %.2f", pFinal);
  printf("\n Valor das parcelas: %.2f", vParcelas);
  printf("\n==========================================\n");
  printf("\n\n Compra finalizada com sucesso.");
  int espere;
  printf("\n\n Digite qualquer valor para retornar ao menu:");
  scanf("%d", &espere);
}
 
int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int rodando = 1;

  //roda o sistema de forma contínua
  while(rodando == 1)
  {
    int v;
    int option = 0;
    Mensagem(0);
    scanf("%d", &option);

    if(option == 1) 
    {
      Comprar();
      system("cls");
    }
    else if(option == 2)
    {
      Mensagem(1);
      scanf("%d", &v);
      system("cls");
    }
    else if(option == 3)
      rodando = 0;
      system("cls");
  }

  SetConsoleOutputCP(CPAGE_DEFAULT);
  return 0;
}
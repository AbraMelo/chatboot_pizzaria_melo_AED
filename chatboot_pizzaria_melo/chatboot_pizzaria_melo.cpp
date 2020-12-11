#include <iostream>
#include <fstream>
#include <string>
#include <speechapi_cxx.h>
#include <locale.h>


using namespace std;
using namespace Microsoft::CognitiveServices::Speech;
using namespace Microsoft::CognitiveServices::Speech::Audio;

auto autenticacao = SpeechConfig::FromSubscription("ad4616a7fc9b4dbf8579fe3ce81f355a", "southcentralus"); // DECLARAÇÃO DA AUTENTICAÇÃO DO RECURSO
auto requisicao_textofala = SpeechSynthesizer::FromConfig(autenticacao); // DECLARAÇÃO DO OBJETO DE REQUISIÇÃO DE TEXTO EM FALA DO RECURSO
auto audio_config = AudioConfig::FromDefaultMicrophoneInput(); // DECLARAÇÃO DA ENTRADA DO MICROFONE
auto requisicao_falatexto = SpeechRecognizer::FromConfig(autenticacao, audio_config); // DECLARAÇÃO DO OBJETO DE REQUISIÇÃO DE FALA EM TEXTO DO RECURSO

// PROCEDIMENTO QUE REQUISITA DA API A TRANSFORMAÇÃO DE UM TEXTO EM FALA
void texto_em_fala(string Texto)
{
   
    cout << Texto + "\n";
    requisicao_textofala->SpeakTextAsync(Texto).get(); // REQUISIÇÃO DA SINTETIZAÇÃO DE TEXTO EM FALA
}
// FUNÇÃO QUE REQUISITA DA API O RECONHECIMENTO DE UMA FALA E A TRANSFORMAÇÃO DESSA FALA EM UM TEXTO
string fala_em_texto() {
    auto resultado = requisicao_falatexto->RecognizeOnceAsync().get(); // REQUISIÇÃO DO RECONHEIMENTO DE FALA EM TEXTO
    cout << resultado->Text + "\n";
    return resultado->Text; //CONVERSÃO DO RESULTADO DO RECONHECIMENTO EM TEXTO
}

int main()
{

    autenticacao->SetSpeechRecognitionLanguage("pt-BR");                //  CONFIGURAÇÃO DA AUTENTICAÇÃO PARA O RECONHECIMENTO DE FALA EM PORTUGUÊS 
    autenticacao->SetSpeechSynthesisLanguage("pt-BR");                  //  CONFIGURAÇÃO DA AUTENTICAÇÃO PARA A SINTETIZAÇÃO DE FALA EM PORTUGUÊS 
    autenticacao->SetSpeechSynthesisVoiceName("pt-BR-HeloisaRUS"); //pt-BR-Daniel  // CONFIGURAÇÃO DA AUTENTICAÇÃO COM UMA VOZ ESPECÍFICA 
    requisicao_textofala = SpeechSynthesizer::FromConfig(autenticacao); //  REDEFINIÇÃO DO OBJETO REQUISICAO_TEXTOFALA COM AS NOVAS CONFIGURAÇÕES 
    requisicao_falatexto = SpeechRecognizer::FromConfig(autenticacao, audio_config); //  REDEFINIÇÃO DO OBJETO REQUISICAO_FALATEXTO COM AS NOVAS CONFIGURAÇÕES


    try
    {

        setlocale(LC_ALL, "pt_BR.UTF-8");   //Lingua Portuguesa para acentuar as palavras.

        char escolha;   //Declaração da variável para caso a pessoa queira fazer outro pedido.

        do {
            //Introdução ao pedido, o cliente escolhe o sabor da pizza.
            texto_em_fala("Seja Bem Vindo a Pizzaria Melo");
            texto_em_fala("Qual é o seu nome?");
            string nome = fala_em_texto();
            texto_em_fala("Olá " + nome + " Aqui está o nosso menu de sabores de Pizzas");
            texto_em_fala("Calabresa");
            texto_em_fala("Mussarela");
            texto_em_fala("Presunto");
            texto_em_fala("Qual você deseja?");
            string opcao = fala_em_texto();
            //Caso a opção escolhida seja Calabresa.
            if (opcao == ("Calabresa.")) {
                texto_em_fala("Qual tamanho de pizza você deseja?");    //Usuário escolhe o tamanho da pizza.
                texto_em_fala("A Grande é 30 reais e a Pequena 15 reais");
                string tamanho = fala_em_texto();
                //Caso a opção escolhida seja tamanho Grande.
                if (tamanho == ("Grande.")) {
                    texto_em_fala("Uma bebida para acompanhar: As duas opções possuem o mesmo valor de 5 reais:");  //Usuário escolhe o uma bebida.
                    texto_em_fala("Suco ou Refrigerante?");
                    string bebidas = fala_em_texto();
                    //Caso a opção escolhida seja Suco.
                    if (bebidas == ("Suco.")) {
                        texto_em_fala("Vamos finalizar com uma sobremesa, é por conta da casa. Qual é o doce de sua escolha?"); //Escolha da sobremesa.
                        texto_em_fala("Chocolate ou Morango");
                        string doce = fala_em_texto();
                        //Caso a opção escolhida seja Chocolate.
                        if (doce == ("Chocolate.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 35,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");    //Agradecimento final da pizzaria.
                        }
                        //Caso a opção escolhida seja Morango.
                        if (doce == ("Morango.")) {
                            texto_em_fala("Anotando seu pedido...");  
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 35,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                    }
                    //Caso a opção escolhida seja Refrigerante.
                    if (bebidas == ("Refrigerante.")) {
                        texto_em_fala("Vamos finalizar com uma sobremesa, é por conta da casa. Qual é o doce de sua escolha?"); //Escolha da sobremesa.
                        texto_em_fala("Chocolate ou Morango");
                        string doce = fala_em_texto();
                        //Caso a opção escolhida seja Chocolate.
                        if (doce == ("Chocolate.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 35,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                        //Caso a opção escolhida seja Morango.
                        if (doce == ("Morango.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 35,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                    }
                }
                //Caso a opção escolhida seja tamanho Pequeno.
                if (tamanho == ("Pequena.")) {
                    texto_em_fala("Uma bebida para acompanhar: As duas opções possuem o mesmo valor de 5 reais:");  //Usuário escolhe o uma bebida.
                    texto_em_fala("Suco ou Refrigerante?"); 
                    string bebidas = fala_em_texto();
                    //Caso a opção escolhida seja Suco.
                    if (bebidas == ("Suco.")) {
                        texto_em_fala("Vamos finalizar com uma sobremesa, é por conta da casa. Qual é o doce de sua escolha?"); //Escolha da sobremesa.
                        texto_em_fala("Chocolate ou Morango");
                        string doce = fala_em_texto();
                        //Caso a opção escolhida seja Chocolate.
                        if (doce == ("Chocolate.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 20,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                        //Caso a opção escolhida seja Morango.
                        if (doce == ("Morango.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 20,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                    }
                    //Caso a opção escolhida seja Refrigerante.
                    if (bebidas == ("Refrigerante.")) {
                        texto_em_fala("Vamos finalizar com uma sobremesa, é por conta da casa. Qual é o doce de sua escolha?"); //Escolha da sobremesa.
                        texto_em_fala("Chocolate ou Morango");
                        string doce = fala_em_texto();
                        //Caso a opção escolhida seja Chocolate.
                        if (doce == ("Chocolate.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 20,00");  //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                        //Caso a opção escolhida seja Morango.
                        if (doce == ("Morango.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 20,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                    }
                }
            }

            //Caso a opção escolhida seja Mussarela.
            if (opcao == ("Mussarela.")) {
                texto_em_fala("Qual tamanho de pizza você deseja?");    //Usuário escolhe o tamanho da pizza.
                texto_em_fala("A Grande é 30 reais e a Pequena 15 reais");
                string tamanho = fala_em_texto();
                //Caso a opção escolhida seja tamanho Grande.
                if (tamanho == ("Grande.")) {
                    texto_em_fala("Uma bebida para acompanhar: As duas opções possuem o mesmo valor de 5 reais:");  //Usuário escolhe o uma bebida.
                    texto_em_fala("Suco ou Refrigerante?");
                    string bebidas = fala_em_texto();
                    //Caso a opção escolhida seja Suco.
                    if (bebidas == ("Suco.")) {
                        texto_em_fala("Vamos finalizar com uma sobremesa, é por conta da casa. Qual é o doce de sua escolha?"); //Escolha da sobremesa.
                        texto_em_fala("Chocolate ou Morango");
                        string doce = fala_em_texto();
                        //Caso a opção escolhida seja Chocolate.
                        if (doce == ("Chocolate.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 35,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");    //Agradecimento final da pizzaria.
                        }
                        //Caso a opção escolhida seja Morango.
                        if (doce == ("Morango.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 35,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                    }
                    //Caso a opção escolhida seja Refrigerante.
                    if (bebidas == ("Refrigerante.")) {
                        texto_em_fala("Vamos finalizar com uma sobremesa, é por conta da casa. Qual é o doce de sua escolha?"); //Escolha da sobremesa.
                        texto_em_fala("Chocolate ou Morango");
                        string doce = fala_em_texto();
                        //Caso a opção escolhida seja Chocolate.
                        if (doce == ("Chocolate.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 35,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                        //Caso a opção escolhida seja Morango.
                        if (doce == ("Morango.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 35,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                    }
                }
                //Caso a opção escolhida seja tamanho Pequeno.
                if (tamanho == ("Pequena.")) {
                    texto_em_fala("Uma bebida para acompanhar: As duas opções possuem o mesmo valor de 5 reais:");  //Usuário escolhe o uma bebida.
                    texto_em_fala("Suco ou Refrigerante?");
                    string bebidas = fala_em_texto();
                    //Caso a opção escolhida seja Suco.
                    if (bebidas == ("Suco.")) {
                        texto_em_fala("Vamos finalizar com uma sobremesa, é por conta da casa. Qual é o doce de sua escolha?"); //Escolha da sobremesa.
                        texto_em_fala("Chocolate ou Morango");
                        string doce = fala_em_texto();
                        //Caso a opção escolhida seja Chocolate.
                        if (doce == ("Chocolate.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 20,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                        //Caso a opção escolhida seja Morango.
                        if (doce == ("Morango.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 20,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                    }
                    //Caso a opção escolhida seja Refrigerante.
                    if (bebidas == ("Refrigerante.")) {
                        texto_em_fala("Vamos finalizar com uma sobremesa, é por conta da casa. Qual é o doce de sua escolha?"); //Escolha da sobremesa.
                        texto_em_fala("Chocolate ou Morango");
                        string doce = fala_em_texto();
                        //Caso a opção escolhida seja Chocolate.
                        if (doce == ("Chocolate.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 20,00");  //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                        //Caso a opção escolhida seja Morango.
                        if (doce == ("Morango.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 20,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                    }
                }
            }

            //Caso a opção escolhida seja Presunto.
            if (opcao == ("Presunto.")) {
                texto_em_fala("Qual tamanho de pizza você deseja?");    //Usuário escolhe o tamanho da pizza.
                texto_em_fala("A Grande é 30 reais e a Pequena 15 reais");
                string tamanho = fala_em_texto();
                //Caso a opção escolhida seja tamanho Grande.
                if (tamanho == ("Grande.")) {
                    texto_em_fala("Uma bebida para acompanhar: As duas opções possuem o mesmo valor de 5 reais:");  //Usuário escolhe o uma bebida.
                    texto_em_fala("Suco ou Refrigerante?");
                    string bebidas = fala_em_texto();
                    //Caso a opção escolhida seja Suco.
                    if (bebidas == ("Suco.")) {
                        texto_em_fala("Vamos finalizar com uma sobremesa, é por conta da casa. Qual é o doce de sua escolha?"); //Escolha da sobremesa.
                        texto_em_fala("Chocolate ou Morango");
                        string doce = fala_em_texto();
                        //Caso a opção escolhida seja Chocolate.
                        if (doce == ("Chocolate.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 35,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");    //Agradecimento final da pizzaria.
                        }
                        //Caso a opção escolhida seja Morango.
                        if (doce == ("Morango.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 35,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                    }
                    //Caso a opção escolhida seja Refrigerante.
                    if (bebidas == ("Refrigerante.")) {
                        texto_em_fala("Vamos finalizar com uma sobremesa, é por conta da casa. Qual é o doce de sua escolha?"); //Escolha da sobremesa.
                        texto_em_fala("Chocolate ou Morango");
                        string doce = fala_em_texto();
                        //Caso a opção escolhida seja Chocolate.
                        if (doce == ("Chocolate.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 35,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                        //Caso a opção escolhida seja Morango.
                        if (doce == ("Morango.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 35,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                    }
                }
                //Caso a opção escolhida seja tamanho Pequeno.
                if (tamanho == ("Pequena.")) {
                    texto_em_fala("Uma bebida para acompanhar: As duas opções possuem o mesmo valor de 5 reais:");  //Usuário escolhe o uma bebida.
                    texto_em_fala("Suco ou Refrigerante?");
                    string bebidas = fala_em_texto();
                    //Caso a opção escolhida seja Suco.
                    if (bebidas == ("Suco.")) {
                        texto_em_fala("Vamos finalizar com uma sobremesa, é por conta da casa. Qual é o doce de sua escolha?"); //Escolha da sobremesa.
                        texto_em_fala("Chocolate ou Morango");
                        string doce = fala_em_texto();
                        //Caso a opção escolhida seja Chocolate.
                        if (doce == ("Chocolate.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 20,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                        //Caso a opção escolhida seja Morango.
                        if (doce == ("Morango.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 20,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                    }
                    //Caso a opção escolhida seja Refrigerante.
                    if (bebidas == ("Refrigerante.")) {
                        texto_em_fala("Vamos finalizar com uma sobremesa, é por conta da casa. Qual é o doce de sua escolha?"); //Escolha da sobremesa.
                        texto_em_fala("Chocolate ou Morango");
                        string doce = fala_em_texto();
                        //Caso a opção escolhida seja Chocolate.
                        if (doce == ("Chocolate.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 20,00");  //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                        //Caso a opção escolhida seja Morango.
                        if (doce == ("Morango.")) {
                            texto_em_fala("Anotando seu pedido...");
                            texto_em_fala("Voce pediu uma pizza de " + opcao + " Com um " + bebidas + " E um doce de " + doce + "");    //Confirmação do pedido.
                            texto_em_fala("O valor a ser pago é R$ 20,00"); //Preço total.
                            texto_em_fala("Como deseja Pagar?");    //Forma de pagamento é informada.
                            string pagamento = fala_em_texto();
                            texto_em_fala("Tudo certo com o seu pedido, obrigado por conversar comigo e pedir uma deliciosa pizza na Pizzaria Melo");   //Agradecimento final da pizzaria.
                        }
                    }
                }
            }
            //Caso o usuário fale algo diferente do solicitado.
            else {
                texto_em_fala("Opção Inválida");
            }

            texto_em_fala("Deseja fazer ou reptir um pedido?\nDigite S para Sim\nDigite N para Não");
            cin >> escolha;

        } while (escolha == 'S');

        texto_em_fala("Obrigado, Volte Sempre");
    }
    catch (exception e)
    {
        cout << e.what();
    }
    return 0;
}


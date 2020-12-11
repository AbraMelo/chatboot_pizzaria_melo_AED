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

        setlocale(LC_ALL, "pt_BR.UTF-8");

        int op;

        //do{
        texto_em_fala("Seja Bem Vindo a Pizzaria Melo");
        texto_em_fala("Qual é o seu nome?");
        string nome = fala_em_texto();
        texto_em_fala("Ola " + nome + " Aqui está o nosso menu de sabores de Pizzas");
        texto_em_fala("Calabresa");
        texto_em_fala("Mussarela");
        texto_em_fala("Presunto");
        texto_em_fala("Qual você deseja?");
        string opcao = fala_em_texto();


        if (opcao == ("Calabresa.")) {
            texto_em_fala("Qual tamanho de pizza você deseja?");
            texto_em_fala("A Grande é 30 reais e a Pequena 15 reais");
            string tamanho = fala_em_texto();
            if (tamanho == ("Grande.")) {
                texto_em_fala("Qual será a sua bebida?");
                texto_em_fala("Suco ou Refrigerante");
                string bebida = fala_em_texto();
                texto_em_fala("Uma Pizza de" + opcao + "," + tamanho + "com um" + bebida + "");
            }
            if (tamanho == ("Pequena.")) {
                texto_em_fala("Qual será a sua bebida? Elas possuem o preço de 5 reais");
                texto_em_fala("Suco ou Refrigerante");
                string bebida = fala_em_texto();
                texto_em_fala("Uma Pizza de" + opcao + "," + tamanho + "com um" + bebida + "");
            }

        }
        else {
            texto_em_fala("Opção Inválida");
        }

        /*
            if
            string sabores = fala_em_texto();
            if (sabores == ("Calabresa.")) {
                texto_em_fala("Deseja alguma bebida?");

                texto_em_fala("Anotando o seu pedido...");
                texto_em_fala("Qual será a forma de pagamento?");
                texto_em_fala("Crédito ou Débito ou Dinheiro");
                string pagamento = fala_em_texto();
            }
            if (sabores == ("Mussarela.")) {
                texto_em_fala("Anotando o seu pedido...");
                texto_em_fala("Qual será a forma de pagamento?");
                texto_em_fala("Crédito ou Débito ou Dinheiro");
                string pagamento = fala_em_texto();
            }
            if (sabores == ("Presunto.")) {
                texto_em_fala("Anotando o seu pedido...");
                texto_em_fala("Qual será a forma de pagamento?");
                texto_em_fala("Crédito ou Débito ou Dinheiro");
                string pagamento = fala_em_texto();
            }
            else {
            texto_em_fala("Opção Inválida");
            }
        }
        if (opcao == ("Sobremesas.")) {
            texto_em_fala("Quais doces você deseja?");
            texto_em_fala("Chocolate ou Morango");
            string doces = fala_em_texto();

            if (doces == ("Chocolate.")) {
                texto_em_fala("Anotando o seu pedido...");
                texto_em_fala("Qual será a forma de pagamento?");
                texto_em_fala("Crédito ou Débito ou Dinheiro");
                string pagamento = fala_em_texto();
            }
            else if (doces == ("Morango.")) {
                texto_em_fala("Anotando o seu pedido...");
                texto_em_fala("Qual será a forma de pagamento?");
                texto_em_fala("Crédito ou Débito ou Dinheiro");
                string pagamento = fala_em_texto();
            }
        else {
           texto_em_fala("Opção Inválida");
        }
        }
        if (opcao == ("Bebidas.")) {
            texto_em_fala("Qual bebida você deseja?");
            texto_em_fala("Suco ou Refrigerante");
            string bebidas = fala_em_texto();
            if (bebidas == ("Suco.")) {
                texto_em_fala("Anotando o seu pedido...");
                texto_em_fala("Qual será a forma de pagamento?");
                texto_em_fala("Crédito ou Débito ou Dinheiro");
                string pagamento = fala_em_texto();
            }
            else if (bebidas == ("Refrigerante. ")) {
                texto_em_fala("Anotando o seu pedido...");
                texto_em_fala("Qual será a forma de pagamento?");
                texto_em_fala("Crédito ou Débito ou Dinheiro");
                string pagamento = fala_em_texto();
            }
        else {
           texto_em_fala("Opção Inválida");
        }
        }

        texto_em_fala("Digite 1 se deseja algo mais ou 2 se deseja sair:");
        cin >> op;

    } while(op==1);

    texto_em_fala("Obrigado, Volte Sempre!");
    */
    }
    catch (exception e)
    {
        cout << e.what();
    }
    return 0;
}


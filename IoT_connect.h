#ifndef esp9266wifi_h
#include <ESP8266WiFi.h>
#endif

#ifndef wificlient_h
#include <WiFiClient.h>
#endif

#ifndef esp8266webserver_h
#include <ESP8266WebServer.h>
#endif

typedef String Comando;
typedef String Pagina;

class Site{
    private:
       IPAddress  enderecoPlaca;
       IPAddress  roteador;
       String     ssid;
       String     password;
       
       String     botoes[10][2];
       int        indexBotoes;

       WiFiClient wifiClient;
       WiFiServer *server;

       String     titulo;
       String     cabecalho;
       String     rodape;
       int        modoDebug=0;
       String     corFundoPagina;

    public: 

       Site();
       void      definirIP(int oc1, int oc2, int oc3, int oc4);
       void      inserirComando(String botao, String comando);  
       Comando   receberComando();
       int       compararComando(String comando, String nome);
       void      inicializar();
       int       temConexao();
       void      conectarNaRede(String ssid, String senha); 
       void      gerarPaginaHTML();
       void      definirModoDebug(int modo);
       void      definirModoRoteador(char* ssid, char* password, int channel);
};

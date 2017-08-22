#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "IoT_connect.h"

Site::Site(){
	Serial.begin(115200);

}
void   Site::definirIP(int oc1, int oc2, int oc3, int oc4){
	if (modoDebug){
		Serial.println("Definindo endereco IP");
		Serial.print(oc1);
		Serial.print(".");
		Serial.print(oc2);
		Serial.print(".");
		Serial.print(oc3);
		Serial.print(".");
		Serial.println(oc4);
	}
	IPAddress _rote(oc1, oc2, oc3, 1);
	IPAddress _plac(oc1, oc2, oc3, oc4);
	IPAddress _mask(255,255,255,0);

	enderecoPlaca = _plac;
	roteador      = _rote;

	WiFi.config(enderecoPlaca, roteador, _mask);

}

void   Site::inicializar(){	
	server = new WiFiServer(80);
	server->begin();
	if (modoDebug){
		Serial.println("Servidor Inicializado!");
	}
}


void   Site::inserirComando(String botao, String comando){
	botoes[indexBotoes][0] = botao;
	botoes[indexBotoes][1] = comando;
	indexBotoes++;
	if (modoDebug){
		Serial.println("Comando Adicionado!");
	}
} 

String    Site::receberComando(){
	String linha = wifiClient.readStringUntil('\n');
	if (modoDebug){
		Serial.print("URL Received: ");
		Serial.println(linha);
	}
	wifiClient.flush();
	return (linha);
}

int    Site::compararComando(String comando, String nome){
	return (comando.indexOf(nome) != -1? 1: 0);
}

void   Site::conectarNaRede(String ssid, String senha){
	char* ch_ssid;
	char* ch_senha;
	ssid.toCharArray(ch_ssid, ssid.length());
	senha.toCharArray(ch_senha, senha.length());
	WiFi.begin(ch_ssid, ch_senha);
    while (WiFi.status() != WL_CONNECTED){
		delay(500);
		Serial.print(".");
	}
}

void  Site::definirModoDebug(int modo){
	modoDebug = modo;
	Serial.println("Definindo Modo debug - LIGADO");
}

int   Site::temConexao(){
	//Serial.println("Aguardando Cliente.");
    wifiClient = server->available();
    if (!wifiClient){
    	return 0;
    }
    while(!wifiClient.available()){
		delay(1);
	}
	return 1;
	
} 

void   Site::definirModoRoteador(char* ssid, char* password, int channel){
	WiFi.setMode(WIFI_AP);
	WiFi.softAP(ssid,password,channel);
}
void   Site::gerarPaginaHTML(){
	String s="HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n";
	s +="<html>\r\n";
	s += "<head>\r\n";
	s +=" <title> .: IoT_Connect :. </title> \r\n";
	s +=" <style>";
	s +=" a{background-color:BLUE; color:WHITE; font-size:100px};";
	s +="";
	s +="";
	s +="";
	s +=" </style>";
	
	s += "</head>\r\n";
	s += "<body>\r\n";

	s += "<h1>Welcome to IoT Connect Library</h1>\r\n";
	for (int i=0;i<indexBotoes;i++){
		s+="<a href=\"?"+botoes[i][1]+"\">"+botoes[i][0]+"</a><br/>";
	}
	s += "</body>\r\n";
	s +="</html>";
	wifiClient.print(s);
	wifiClient.flush();
	wifiClient.stop();

}

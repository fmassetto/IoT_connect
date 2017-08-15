# IoT_connect

Biblioteca para facilitar a programação de dispositivos baseados no ESP8266. O objetivo é tornar o ESP um tipo de "controle remoto" da automação feita. Através desta biblioteca, é possível criar uma página HTML genérica que contém botões associados a comandos.

## Funções e Objetos Disponíveis

### Site
Objeto que contém todos os controles de um site.

### Site.definirIP(valor1, valor2, valor3, valor4)
Define o Endereço IP que irá ser atribuído ao site. Composto dos 4 octetos no formato valor1.valor2.valor3.valor4 
Cada um dos valores deverá ser entre 0 e 255. Este é um elemento opcional, uma vez que o Roteador, ao conectar o dispositivo ESP irá atribuir um endereço IP a ele.

### Site.conectarNaRede(ssid, password)
Conecta o dispositivo na rede WiFi disponível. O parâmetro SSID define o Nome da Rede e PASSWORD define a senha

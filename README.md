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

### Site.inserirComando(Rótulo, comando)
Insere um novo comando no site padrão. Este comando irá gerar um botão cujo texto é informado no parâmetro "Rótulo" e o comando correspondente no parâmetro "comando".

### Site.definirModoDebug(debug)
Define o modo debug para 0-desligado ou 1-Ligado. Isso irá emitir mensagens no monitor Serial. Detalhe: o monitor serial deverá estar configurado na mesma velocidade de comunicação da placa. O ESP8266 em geral utiliza uma taxa de transmissão 115200.

### Site.inicializar()
Uma vez tudo configurado, é só inicializar o site e seu servidor. Desse modo, o site já está disponível para receber conexões.

### Site.temConexao()
Verifica se existe algum dispositivo conectado no ESP. Caso exista, basta apenas gerar a Página HTML 

### Site.gerarPaginaHTML()
Gera a página HTML padrão que será exibida ao usuário em seu tablet

### Site.receberComando()
Recebe um comando via URL do usuário e retorna em uma variável do tipo "Comando" (vide abaixo)

### Site.compararComando(Comando, texto)
Compara o conteúdo do comando com um texto pré-definido. Retorna 1 se forem idênticos ou 0 se forem diferentes

## Novos Tipos de Dados

### Comando 
Define um texto que contem o comando recebido pela URL do site

### Pagina
Estrutura de dados que contem o texto da página HTML customizada a ser gerado para o usuário

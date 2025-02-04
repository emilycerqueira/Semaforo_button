# Sistema de Temporização com LEDs e Botão 🚦

Este projeto implementa um sistema de temporização utilizando o microcontrolador Raspberry Pi Pico, três LEDs (vermelho, amarelo e verde), e um botão. O código foi desenvolvido em C, utilizando a ferramenta Pico SDK.

📋 **Descrição do Projeto**

Este sistema de LEDs alterna entre os três LEDs (vermelho, amarelo e verde) com um atraso de 3 segundos entre cada troca. A sequência de LEDs começa com todos acesos e vai alternando um a um até que todos estejam apagados. O botão pode ser pressionado para iniciar a sequência de LEDs, mas só será aceito novo clique após a sequência ser completada.

🌟 **Funcionalidade**
- O sistema inicia com todos os LEDs acesos.
- Após 3 segundos, o LED vermelho é desligado, em seguida, o LED amarelo e por fim, o LED verde.
- Durante a execução da sequência, o botão não pode ser pressionado novamente até que todos os LEDs sejam desligados.
- A função de callback controla o tempo entre cada mudança de estado dos LEDs.

🚀 **Requisitos**
- **Microcontrolador**: Raspberry Pi Pico.
- **Editor de Código**: Visual Studio Code (VS Code).
- **SDK do Raspberry Pi Pico** configurado no sistema.

🔌 **Conexões dos GPIOs**
| LED        | Cor        | GPIO |
|------------|------------|------|
| Vermelho   | 🔴 Vermelho| 11   |
| Amarelo    | 🟡 Amarelo | 12   |
| Verde      | 🟢 Verde   | 13   |
| Botão      | 🔲 Botão   | 5    |

⚙️ **Funcionamento do Código**
1. **Inicialização**:
   - Configura os pinos dos LEDs como saída e o pino do botão como entrada com pull-up.
   - Inicia a comunicação serial e prepara o sistema para a interrupção do botão.
   
2. **Sequência de LEDs**:
   - Quando o botão é pressionado, todos os LEDs acendem.
   - A cada 3 segundos, o LED vermelho é desligado, seguido do LED amarelo e, finalmente, o LED verde.

3. **Botão**:
   - O botão inicia a sequência apenas quando todos os LEDs estiverem apagados, garantindo que a sequência não seja interrompida.

📦 **Como Usar**
1. **Instalar o Visual Studio Code**:
   - Acesse o site oficial e faça o download: [Visual Studio Code](https://code.visualstudio.com/).
   - Instale o programa e configure conforme necessário.

2. **Instalar as dependências**:
   - Certifique-se de ter as extensões necessárias:
     - C/C++ (Microsoft).
     - CMake Tools.
     - Raspberry Pi Pico SDK.

3. **Configurar o Projeto**:
   - Clone o repositório para o seu computador.
   
4. **Testar no Hardware Real**:
   - Conecte a placa ao computador e faça o upload do código.
   - Ao pressionar o botão, a sequência de LEDs começará.

🧪 **Simulação**:
   - Você pode testar o código utilizando um ambiente como o [Wokwi](https://wokwi.com/) para simular o comportamento dos LEDs conectados aos GPIOs 11, 12 e 13, e o botão no GPIO 5.

---

🔧 **Observações**:
- Durante a execução da sequência, o botão só pode ser pressionado novamente quando todos os LEDs estiverem apagados, para garantir que a sequência não seja interrompida.

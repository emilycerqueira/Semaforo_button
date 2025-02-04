#include "pico/stdlib.h"
#include "hardware/timer.h"  // Biblioteca para temporizadores

// Definindo os pinos dos LEDs e do botão
#define LED_AZUL       11
#define LED_VERMELHO   12
#define LED_VERDE      13
#define BOTAO           5

// Variável de controle do estado dos LEDs
volatile int estado = 0;
volatile bool aguardando = false;  // Variável para indicar se a sequência está em andamento

// Função de callback para alternar os LEDs
bool turn_off_callback(struct repeating_timer *t) {
    if (estado == 0) {
        gpio_put(LED_AZUL, 1);
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_VERDE, 1);
    } else if (estado == 1) {
        gpio_put(LED_AZUL, 0);
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_VERDE, 1);
    } else if (estado == 2) {
        gpio_put(LED_AZUL, 0);
        gpio_put(LED_VERMELHO, 0);
        gpio_put(LED_VERDE, 1);
    } else if (estado == 3) {
        gpio_put(LED_AZUL, 0);
        gpio_put(LED_VERMELHO, 0);
        gpio_put(LED_VERDE, 0);
        aguardando = false; // Sequência finalizada, botão pode ser pressionado novamente
        return false;  // Parar o temporizador
    }

    estado = (estado + 1) % 4; // Alterne entre 0, 1, 2, e 3 (finaliza no estado 3)
    return true; // Continua o temporizador
}

// Função para verificar o botão
void verificar_botao(uint gpio, uint32_t events) {
    if (gpio == BOTAO && !aguardando) { // Só inicia a sequência se aguardando for falso
        aguardando = true; // Bloqueia o botão até a sequência terminar
        estado = 0; // Começa com todos os LEDs ligados
        gpio_put(LED_AZUL, 1);
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_VERDE, 1);

        // Adiciona o temporizador para alternar os LEDs
        add_repeating_timer_ms(3000, turn_off_callback, NULL, NULL);
    }
}

int main() {
    // Inicializa o sistema serial e os pinos dos LEDs
    stdio_init_all();

    gpio_init(LED_AZUL);
    gpio_init(LED_VERMELHO);
    gpio_init(LED_VERDE);
    gpio_init(BOTAO);

    // Configura os pinos dos LEDs como saída
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Configura o pino do botão como entrada e ativa o pull-up interno
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);

    // Registra a interrupção para detectar o clique do botão
    gpio_set_irq_enabled_with_callback(BOTAO, GPIO_IRQ_EDGE_FALL, true, &verificar_botao);

    while (true) {
        tight_loop_contents(); // Aguarda enquanto o sistema espera o botão ser pressionado
    }

    return 0;
}

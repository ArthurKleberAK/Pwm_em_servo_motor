<!DOCTYPE html>

   # Controle de Servomotor com RP2040 via PWM </h1>
    
   <h2>Descrição</h2>
    <p>Este projeto implementa o controle de um servomotor utilizando o Raspberry Pi Pico W e o <strong>Pico SDK</strong>.O controle é realizado por meio do <strong>PWM (Pulse Width Modulation)</strong>, ajustando o ciclo ativo para posicionar o servo em diferentes ângulos.</p>
    <p>A simulação é feita no <strong>Wokwi</strong>, sem necessidade de circuitos adicionais.</p>
    
   <h2>Requisitos</h2>
    <ul>
        <li>Raspberry Pi Pico W</li>
        <li>Servomotor compatível</li>
        <li>Pico SDK instalado</li>
        <li>Simulador Wokwi </li>
    </ul>
    
   <h2>Configuração do PWM</h2>
    <ul>
        <li><strong>Frequência do PWM:</strong> 50 Hz (período de 20ms)</li>
        <li><strong>Clock divisor:</strong> 64.0</li>
        <li><strong>Valor do WRAP:</strong> 39063</li>
    </ul>
    
   <h2>Funcionamento</h2>
   <ol>
        <li>O programa inicializa o PWM na GPIO <strong>22</strong> com as configurações adequadas.</li>
        <li>Movimenta o servo para <strong>180°</strong>, <strong>90°</strong> e <strong>0°</strong> com pausas de 5 segundos.</li>
        <li>Inicia um ciclo de movimentação suave entre <strong>0° e 180°</strong> com incrementos de 5µs e atraso de 10ms.</li>
    </ol>
    

    
   <h2>Código-Fonte</h2>
    <p>O código-fonte está localizado no arquivo <code>servo_moto.c</code>.</p>

  <h2> Link para do video <h2>
   <p> https://drive.google.com/file/d/1RnTmsUukPJ1WLp50Yy7C7SoN0E081oNS/view?usp=sharing <p>
   <h2>Autor</h2>
    <p>Arthur Kleber Ribeiro Alcantara</p>
</body>
</html>

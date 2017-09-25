/*
Implementado por: Julian Morua Vindas, B54872

Este modulo es parte del bloque de transmision de la capa PHY de PCIe.
Se encarga de recibir 10 bits provenientes de la etapa de codificacion 8b10b.
Estos bits se reciben todos juntos (en paralelo), y el objetivo de este modulo
es tomarlos y expulsarlos de 1 en 1 (en serie) con cada ciclo del reloj.
La logica que se utiliza es tomar el arreglo de 10 bits,y guardarlo en un registro
interno. Luego este de este registro se expulsara el MSb, y todos los bits se
desplazaran un campo a la izquierda. El LSb se pone en estado de alta impedancia.
Esto se hara hasta que un contador que empieza en 0 alcance el valor de 10.
Ademas, el modulo se implementa de tal forma que siempre que cambien los 10bits de
entrada paralelo se vuelva a empezar el proceso. Cuando terminan de mandarse los 10 bits,
la salida en serie se pone en modo de alta impedancia.
*/

module parallel2serial (clk, in_10b, out_1b);
  input clk;
  input [9:0] in_10b;
  output reg out_1b;

  reg [9:0] interno_10b;
  reg [3:0] cont;

  always @(in_10b) begin
    interno_10b <= in_10b;
    cont <= 0;
  end

  always @ (posedge clk) begin
    if (cont != 10) begin
      out_1b <= interno_10b[9];
      interno_10b[9:1] <= interno_10b[8:0];
      interno_10b[0] <= 0;
      cont <= cont + 1;
    end else begin
      out_1b <= 1'bz;
    end
  end
endmodule //parallel2serial

/*
Implementado por: Julian Morua Vindas B54872

Se realizan las pruebas para el modulo parallel2serial. El estandar de PCIe
indica que debe operar a una frecuencia de 2.5GHz, o de 5GHz. Esto corresponde
a un semi-periodo de reloj de 200ps = 0.2ns, o de 100ps = 0.1ns
*/

`timescale 10ps / 1ps
module probador (clk, out_10b, in_1b_c);
//module probador (clk, out_10b, in_1b_c, in_1b_e);
  output reg clk;
  output reg [9:0] out_10b;
  input in_1b_c;
  //input in_1b_e;


  //reloj
  initial begin
    clk = 0;
  end
  always begin
    #20 clk = ~clk;
  end

  //senales
  initial begin
    out_10b = 10'b110100101;
    #500;
    out_10b = 10'b1010101010;
    #500;
    out_10b = 10'b1110010110;
    #500;
    $finish;
  end

  //verificador
  /*always @ (posedge clk) begin
    if ($realtime > 100) begin
      if (in_1b_c != in_1b_e) begin
        $display($realtime,,,"Error: conductual y estructural difieren. 1b_c = %b; 1b_e = %b", in_1b_c, in_1b_e);
      end
    end
  end*/
endmodule //probador

`include "probador.v"
`include "parallel2serial.v"

module testbench;
  wire w_clk;
  wire w_1b;
  wire [9:0] w_10b;

  probador prob(w_clk, w_10b, w_1b);
  parallel2serial p2s(w_clk, w_10b, w_1b);

  initial begin
    $dumpfile("config_waves.vcd");
    $dumpvars(0, testbench);
  end

endmodule //testbench

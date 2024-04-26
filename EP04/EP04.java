import java.io.*;

class EP04 {
    public static void main(String[] args) throws Exception {
        // abrindo os arquivos
        RandomAccessFile arqLeitura = new RandomAccessFile("testeula.ula", "rw");
        RandomAccessFile arqEscrita = new RandomAccessFile("testeula.hex", "rw");

        if (arqEscrita.length() > 0)
            arqEscrita.setLength(0);

        String linha;
        String[] letras;
        String codigo;
        String x = null, y = null, w = null;

        // ler a primeira linha e desconsidera-la (eh a palavra "inicio:")
        linha = arqLeitura.readLine();

        // verifica se nao eh o fim tirando possiveis espaços em branco
        while (linha != null && (!linha.trim().equals("fim.") && !linha.trim().equals("fim"))) {
            letras = linha.split("(?!^)");// separando a string lida em um array

            if (letras[0].equals("X")) // pegando o valor de X, se for o caso
                x = letras[2];
            else if (letras[0].equals("Y")) // pegando o valor de Y, se for o caso
                y = letras[2];
            else if (letras[0].equals("W")) {// pegando o valor de W, se for o caso, e mostra resultado
                w = decodificador(linha);
                codigo = x + y + w;
                arqEscrita.writeBytes(codigo);
                arqEscrita.writeByte(' ');
            }

            linha = arqLeitura.readLine(); // le a proxima linha
        }

        arqEscrita.writeByte('Z');
        // fechando arquivos
        arqLeitura.close();
        arqEscrita.close();
    }

    public static String decodificador(String w) throws Exception {
        String OPCode = null;

        // verificando qual o conteudo da linha lida, ou seja, qual o OP Code da
        // operacao a ser executada
        // trim() pra tirar possiveis espaços em branco que tiverem na linha
        if (w.trim().equals("W=nB;") || w.trim().equals("W=nB"))
            OPCode = "0";
        else if (w.trim().equals("W=nAeBn;") || w.trim().equals("W=nAeBn"))
            OPCode = "1";
        else if (w.trim().equals("W=nAeB;") || w.trim().equals("W=nAeB"))
            OPCode = "2";
        else if (w.trim().equals("W=Lzero;") || w.trim().equals("W=Lzero"))
            OPCode = "3";
        else if (w.trim().equals("W=AeBn;") || w.trim().equals("W=AeBn"))
            OPCode = "4";
        else if (w.trim().equals("W=nA;") || w.trim().equals("W=nA"))
            OPCode = "5";
        else if (w.trim().equals("W=AxB;") || w.trim().equals("W=AxB"))
            OPCode = "6";
        else if (w.trim().equals("W=AenB;") || w.trim().equals("W=AenB"))
            OPCode = "7";
        else if (w.trim().equals("W=nAonB;") || w.trim().equals("W=nAonB"))
            OPCode = "8";
        else if (w.trim().equals("W=nAxnB;") || w.trim().equals("W=nAxnB"))
            OPCode = "9";
        else if (w.trim().equals("W=Bcopia;") || w.trim().equals("W=Bcopia"))
            OPCode = "A";
        else if (w.trim().equals("W=AeB;") || w.trim().equals("W=AeB"))
            OPCode = "B";
        else if (w.trim().equals("W=Lum;") || w.trim().equals("W=Lum"))
            OPCode = "C";
        else if (w.trim().equals("W=AonB;") || w.trim().equals("W=AonB"))
            OPCode = "D";
        else if (w.trim().equals("W=AoB;") || w.trim().equals("W=AoB"))
            OPCode = "E";
        else if (w.trim().equals("W=Acopia;") || w.trim().equals("W=Acopia"))
            OPCode = "F";

        return OPCode;
    }
}

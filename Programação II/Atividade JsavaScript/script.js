
document.addEventListener("DOMContentLoaded", function() {  
    const bt1 = document.getElementById("bt1");
    bt1.addEventListener("click", olaMundo)

    const bt2 = document.getElementById("bt2");
    bt2.addEventListener("click", mudarCor)
	
	const bt3 = document.getElementById("bt3");
    bt3.addEventListener("click", mudarCorOrdem)
	
	const bt4 = document.getElementById("bt4");
    bt4.addEventListener("click", criarBotao)

    function olaMundo() {
        window.alert("Olá mundo!")
        document.getElementById("texto").innerHTML = "Olá Mundo!";
    }

    function mudarCor() {
        let cor = window.prompt('Digite uma cor: ')
        bt2.style.backgroundColor = cor
        document.getElementById("texto").innerHTML = 
        `<p>A cor escolhida foi <strong>${cor}</strong>!</p>`
    }
	
	var cores = ["cyan", "red", "purple", "yellow", "gray", "blue"];
	var ordem = 1;
	
	function mudarCorOrdem() {
		if (ordem == 6)
			ordem = 0;
		bt3.style.backgroundColor = cores[ordem];
		ordem += 1;
	}
	
	function criarBotao(){
		document.getElementById("botao").innerHTML =
			`<button id="bt5">Botão novo</button>`
			
		const bt5 = document.getElementById("bt5");
		bt5.addEventListener("click", embaralharBotoes);
		bt5.style.left = "900px"
		
		function embaralharBotoes(){
			bt2.style.backgroundColor = "cyan";
			bt3.style.backgroundColor = "cyan";
			var texto = ["Diga olá para o mundo!", "Mude minha cor", "Mude minha cor automático", "Crie um novo botão"];
			texto = embaralhar(texto);
			var posicao = ["20px", "240px", "460px", "680px"];
			posicao = embaralhar(posicao);
			var botoes = document.querySelectorAll("#bt1, #bt2, #bt3, #bt4");
			for (i = 0; i<4; i++){
				botoes[i].innerHTML = texto[i];
				botoes[i].style.left = posicao[i];
			}
		}
	}
	
	function embaralhar(array) {
		  let indiceAtual = array.length;
		  let indiceAleatorio;

		  while (indiceAtual != 0) {
			indiceAleatorio = Math.floor(Math.random() * indiceAtual);
			indiceAtual--;

			[array[indiceAtual], array[indiceAleatorio]] = [array[indiceAleatorio], array[indiceAtual]];
		  }

		  return array;
		}
	
});



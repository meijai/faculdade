using Microsoft.AspNetCore.Mvc;
using ParceirosDaInclusao.Models;

namespace ParceirosDaInclusao.Controllers
{
    public class DoacaoController : Controller
    {
        [HttpGet]
        public IActionResult Index()
        {
            ViewBag.Campanhas = SeedData.Campanhas; // Opcional, caso precise
            return View();
        }

        [HttpPost]
        public IActionResult RealizarDoacao(decimal valor, bool recorrente, string campanha, string nome, string email)
        {
            if (string.IsNullOrEmpty(campanha))
            {
                TempData["Erro"] = "Selecione uma campanha.";
                return RedirectToAction("Index", "Doacao");
            }

            var doacao = new Doacao
            {
                Id = SeedData.Doacoes.Count + 1,
                Valor = valor,
                Recorrente = recorrente,
                Campanha = campanha,
                Data = DateTime.Now
            };

            SeedData.Doacoes.Add(doacao);

            // Atualiza o valor arrecadado da campanha
            var camp = SeedData.Campanhas.FirstOrDefault(c => c.Nome == campanha);
            if (camp != null)
            {
                camp.Arrecadado += valor;
            }

            // ← LINHA PARA ADICIONAR AQUI
            SeedData.SyncCampanhasArrecadado();

            TempData["Mensagem"] = $"Obrigado! Doação de R$ {valor:N2} para '{campanha}' realizada com sucesso.";

            return RedirectToAction("Confirmacao", "Doacao");
        }

        public IActionResult Confirmacao() => View();
    }
}
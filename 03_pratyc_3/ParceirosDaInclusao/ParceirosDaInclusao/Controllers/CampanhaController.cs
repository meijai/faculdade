using Microsoft.AspNetCore.Mvc;
using ParceirosDaInclusao.Models;

namespace ParceirosDaInclusao.Controllers
{
    public class CampanhaController : Controller
    {
        // Listar todas as campanhas
        public IActionResult Index()
        {
            return View(SeedData.Campanhas);
        }

        // GET: Formulário de criação
        public IActionResult Create()
        {
            return View(new Campanha());
        }

        // POST: Salvar nova campanha
        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult Create(Campanha campanha)
        {
            if (ModelState.IsValid)
            {
                campanha.Id = SeedData.Campanhas.Any() ? SeedData.Campanhas.Max(c => c.Id) + 1 : 1;
                campanha.Arrecadado = 0; // Nova campanha começa com zero

                SeedData.Campanhas.Add(campanha);

                TempData["Mensagem"] = $"Campanha '{campanha.Nome}' criada com sucesso!";
                return RedirectToAction("Index");
            }

            // Se chegar aqui, algo deu errado
            TempData["Erro"] = "Erro ao salvar. Verifique os campos.";
            return View(campanha);
        }

        // Editar campanha
        public IActionResult Edit(int id)
        {
            var campanha = SeedData.Campanhas.FirstOrDefault(c => c.Id == id);
            if (campanha == null) return NotFound();
            return View(campanha);
        }

        [HttpPost]
        public IActionResult Edit(Campanha campanha)
        {
            var existente = SeedData.Campanhas.FirstOrDefault(c => c.Id == campanha.Id);
            if (existente != null)
            {
                existente.Nome = campanha.Nome;
                existente.Meta = campanha.Meta;
                existente.ValorMeta = campanha.ValorMeta;
                existente.Arrecadado = campanha.Arrecadado;   // ← Esta linha estava faltando

                TempData["Mensagem"] = "Campanha atualizada com sucesso!";
                return RedirectToAction("Index");
            }

            TempData["Erro"] = "Campanha não encontrada.";
            return RedirectToAction("Index");
        }

        // Excluir campanha
        public IActionResult Delete(int id)
        {
            var campanha = SeedData.Campanhas.FirstOrDefault(c => c.Id == id);
            if (campanha == null) return NotFound();
            return View(campanha);
        }

        [HttpPost, ActionName("Delete")]
        public IActionResult DeleteConfirmed(int id)
        {
            var campanha = SeedData.Campanhas.FirstOrDefault(c => c.Id == id);
            if (campanha != null)
            {
                SeedData.Campanhas.Remove(campanha);
                TempData["Mensagem"] = "Campanha excluída com sucesso!";
            }
            return RedirectToAction("Index");
        }
    }
}
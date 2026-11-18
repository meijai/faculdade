using Microsoft.AspNetCore.Mvc;
using ParceirosDaInclusao.Models;

namespace ParceirosDaInclusao.Controllers
{
    public class EmpresaController : Controller
    {
        public IActionResult Index() => View();

        [HttpPost]
        public IActionResult Cadastrar(Empresa empresa)
        {
            empresa.Id = SeedData.Empresas.Count + 1;
            SeedData.Empresas.Add(empresa);
            TempData["Mensagem"] = "Empresa cadastrada com sucesso como Parceira!";
            return RedirectToAction("Index");
        }
    }
}
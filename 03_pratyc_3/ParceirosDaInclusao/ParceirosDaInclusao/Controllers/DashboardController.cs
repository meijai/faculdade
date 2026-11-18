using Microsoft.AspNetCore.Mvc;
using ParceirosDaInclusao.Models;

namespace ParceirosDaInclusao.Controllers
{
    public class DashboardController : Controller
    {
        public IActionResult Index()
        {
            // Garante que os dados estão carregados
            if (SeedData.Campanhas.Count == 0)
                SeedData.Initialize();
            else
                SeedData.SyncCampanhasArrecadado();

            var viewModel = new DashboardViewModel
            {
                TotalArrecadado = SeedData.Doacoes.Sum(d => d.Valor),
                DoadoresAtivos = SeedData.Usuarios.Count,
                EmpresasParceiras = SeedData.Empresas.Count,
                Campanhas = SeedData.Campanhas,
                DoacoesRecentes = SeedData.Doacoes
                    .OrderByDescending(d => d.Data)
                    .Take(5)
                    .ToList()
            };

            return View(viewModel);
        }
    }
}
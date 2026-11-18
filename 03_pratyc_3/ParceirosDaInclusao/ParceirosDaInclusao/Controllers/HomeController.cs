using Microsoft.AspNetCore.Mvc;

public class HomeController : Controller
{
    public IActionResult Index()
    {
        if (SeedData.Campanhas.Count == 0)
        {
            SeedData.Initialize();
        }
        else
        {
            SeedData.SyncCampanhasArrecadado();   // ← Adicione esta linha
        }

        return View(SeedData.Campanhas);
    }
}
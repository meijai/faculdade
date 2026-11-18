using ParceirosDaInclusao.Models;

namespace ParceirosDaInclusao.Models
{
    public class DashboardViewModel
    {
        public decimal TotalArrecadado { get; set; }
        public int DoadoresAtivos { get; set; }
        public int EmpresasParceiras { get; set; }
        public List<Campanha> Campanhas { get; set; } = new List<Campanha>();
        public List<Doacao> DoacoesRecentes { get; set; } = new List<Doacao>();
    }
}
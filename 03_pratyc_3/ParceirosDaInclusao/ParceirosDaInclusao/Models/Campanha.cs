public class Campanha
{
    public int Id { get; set; }
    public string Nome { get; set; } = string.Empty;
    public string Meta { get; set; } = string.Empty;
    public decimal ValorMeta { get; set; }
    public decimal Arrecadado { get; set; } = 0;
}
public class Doacao
{
    public int Id { get; set; }
    public decimal Valor { get; set; }
    public DateTime Data { get; set; } = DateTime.Now;
    public bool Recorrente { get; set; }
    public int? UsuarioId { get; set; }
    public string? Campanha { get; set; }
}